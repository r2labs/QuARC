#include <math.h>
#include <iostream>
#include <vector>

#include "ik/vector.hpp"
#include "ik/position.hpp"

struct vector_math_test_fixture {

    ik::position* origin;
    std::vector<ik::vector*>* vecs;

    vector_math_test_fixture() {
        origin = new ik::position(0, 0, 0);
        vecs = new std::vector<ik::vector*>();
        vecs->push_back(new ik::vector(origin, 0, 0, 1));
        vecs->push_back(new ik::vector(origin, 0, 1, 0));
        vecs->push_back(new ik::vector(origin, 0, 1, 1));
        vecs->push_back(new ik::vector(origin, 1, 0, 0));
        vecs->push_back(new ik::vector(origin, 1, 0, 1));
        vecs->push_back(new ik::vector(origin, 1, 1, 0));
        vecs->push_back(new ik::vector(origin, 1, 1, 1));
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
