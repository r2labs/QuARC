#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <functional>

#include "ik/vector.hpp"
#include "ik/position.hpp"

struct vector_math_test_fixture {

    ik::position* origin;
    std::vector<ik::vector*>* vecs;

    enum class populate_method { RANDOM, UNIT, CARDINAL};

    static ik::vector* populate_random(ik::position* origin) {
        int r0 = (int)((float)(rand()) / (float)(RAND_MAX) * (RAND_MAX));
        int r1 = (int)((float)(rand()) / (float)(RAND_MAX) * (RAND_MAX));
        int r2 = (int)((float)(rand()) / (float)(RAND_MAX) * (RAND_MAX));
        return new ik::vector(origin, r0, r1, r2);
    }

    static ik::vector* populate_unit(ik::position* origin) {

        int u = (int)((float)(rand()) / (float)(RAND_MAX * 2.0 - 1.0));
        int theta = (int)((float)(rand()) / (float)(RAND_MAX) * 2*M_PI);

        const float x = sqrt(1  - pow(u, 2))*cos(theta);
        const float y = sqrt(1  - pow(u, 2))*sin(theta);
        const float z = u;

        return new ik::vector(origin, x, y, z);
    }

    static ik::vector* populate_cardinal(ik::position* origin) {
        int r = (int)((float)(rand()) / (float)(RAND_MAX) * 3.0f);
        switch(r) {
        case 0: return new ik::vector(origin, 1, 0, 0); break;
        case 1: return new ik::vector(origin, 0, 1, 0); break;
        case 2: return new ik::vector(origin, 0, 0, 1); break;
        default: exit(1);
        }
    }

    void populate(std::size_t n, ik::vector*(*fn)(ik::position*)) {

        for(std::size_t i=0; i<n; ++i) {
            const auto vec = fn(origin);
            vecs->push_back(vec);
        }
    }

    vector_math_test_fixture(std::size_t num, populate_method mtd) {

        srand(time(0));

        origin = new ik::position(0, 0, 0);
        vecs = new std::vector<ik::vector*>();

        switch(mtd) {
        case populate_method::RANDOM   : populate(num, populate_random);   break;
        case populate_method::UNIT     : populate(num, populate_unit);     break;
        case populate_method::CARDINAL : populate(num, populate_cardinal); break;
        default: exit(1);
        }
    }

    ~vector_math_test_fixture() {
        delete origin;
        vecs->clear();
        delete vecs;
    }
};

int test_mag_normalized() {

    vector_math_test_fixture* f = new vector_math_test_fixture();
    int errors = 0;

    for (std::size_t i=0; i<f->vecs->size(); ++i) {

        const auto v = f->vecs->at(i);

        v->normalize();

        const auto calculated = v->magnitude();
        const auto actual = 1.0f;

        if (fabs(calculated - actual) > pow(10, -6)) {
            ++errors;

            std::cout << "error: " << v->to_string() << " did not have mag = 1\n";
            std::cout << "calculated: " << calculated << "\n"
                      << "actual: " << actual << "\n";

        }
    }

    delete f;
    return errors;
}

int test_angle_between() {

    /* const auto calculated_angle = v0->angle_between(v1); */

    /* std::cout << "angle between v0, v1: " << calculated_angle << "\n"; */

    /* return */
    return 0;
}


int main() {

    int accum = 0;

    accum+= test_mag_normalized();
    accum+= test_angle_between();

    std::cout << "errors: " << accum << "\n";
    return accum;
}
