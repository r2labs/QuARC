#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <functional>

#include "ik/vector.hpp"
#include "ik/position.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>

inline int is_between_inc(int val, int low, int high) { return ((val >= low) && (val <= high)); }

struct vector_math_test_fixture {

    ik::position* origin;
    std::vector<ik::vector*>* vecs;

    enum class populate_method : unsigned int { RANDOM, UNIT, CARDINAL };

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

        BOOST_REQUIRE(is_between_inc(r, 0, 2));
        switch(r) {
        case 0: return new ik::vector(origin, 1, 0, 0);
        case 1: return new ik::vector(origin, 0, 1, 0);
        default: return new ik::vector(origin, 0, 0, 1);
        }
    }

    void populate(std::size_t n, ik::vector*(*fn)(ik::position*)) {

        for(std::size_t i=0; i<n; ++i) {
            const auto vec = fn(origin);
            vecs->push_back(vec);
        }
    }

    vector_math_test_fixture() { }

    void initialize(std::size_t num, populate_method mtd) {

        srand(time(0));

        origin = new ik::position(0, 0, 0);
        vecs = new std::vector<ik::vector*>();

        BOOST_REQUIRE(is_between_inc((int)mtd, 0, 2));
        switch(mtd) {
        case populate_method::RANDOM   : populate(num, populate_random);   break;
        case populate_method::UNIT     : populate(num, populate_unit);     break;
        case populate_method::CARDINAL : populate(num, populate_cardinal); break;
        }
    }

    ~vector_math_test_fixture() {
        delete origin;
        for(std::size_t i=0; i<vecs->size(); ++i) {
            delete vecs->at(i);
        }
        delete vecs;
    }
};

BOOST_FIXTURE_TEST_SUITE(vector_math, vector_math_test_fixture)

BOOST_AUTO_TEST_CASE(mag_unit_vector) {

    initialize(1000, vector_math_test_fixture::populate_method::UNIT);

    for (std::size_t i=0; i<vecs->size(); ++i) {

        const auto v = vecs->at(i);

        const auto calculated = v->magnitude();
        const auto actual = 1.0f;

        /* if (fabs(calculated - actual) > pow(10, -6)) { */
        /*     std::cout << "error: " << v->to_string() << " did not have mag = 1\n"; */
        /*     std::cout << "calculated: " << calculated << "\n" */
        /*               << "actual: " << actual << "\n"; */
        /* } */

        BOOST_CHECK(fabs(calculated - actual) < pow(10, -6));
    }
}

BOOST_AUTO_TEST_CASE(mag_normalized_vector) {

    initialize(1000, vector_math_test_fixture::populate_method::RANDOM);

    for (std::size_t i=0; i<vecs->size(); ++i) {

        const auto v = vecs->at(i);

        v->normalize();

        const auto calculated = v->magnitude();
        const auto actual = 1.0f;

        /* if (fabs(calculated - actual) > pow(10, -6)) { */
        /*     std::cout << "error: " << v->to_string() << " did not have mag = 1\n"; */
        /*     std::cout << "calculated: " << calculated << "\n" */
        /*               << "actual: " << actual << "\n"; */
        /* } */

        BOOST_CHECK(fabs(calculated - actual) < pow(10, -6));
    }
}

BOOST_AUTO_TEST_CASE(angle_between_vectors) {

    initialize(1000, vector_math_test_fixture::populate_method::CARDINAL);

    const auto num_elements = vecs->size();
    std::size_t num_same = 0;
    std::size_t num_diff = 0;

    float actual;
    float calculated;

    for(std::size_t i=0; i<num_elements; ++i) {
        const auto v0 = vecs->at(i);
        for(std::size_t j=0; j<num_elements; ++j) {
            const auto v1 = vecs->at(j);
            calculated = v1->angle_between(v0);
            if (v0->close_to(v1)) {
                ++num_same;
                actual = 0.0f;
            } else {
                ++num_diff;
                actual = M_PI/2.0f;
            }

            BOOST_CHECK(fabs(calculated - actual) < pow(10, -6));
            /* if (fabs(calculated - actual) > pow(10, -6)) { */
            /*     std::cout << "error: incorrect angle between " */
            /*               << v0->to_string() << ", " */
            /*               << v1->to_string() << "\n"; */
            /*     std::cout << "calculated: " << calculated << "\n" */
            /*               << "actual: " << actual << "\n"; */
            /* } */
        }
    }

    BOOST_REQUIRE(num_same > (pow(num_elements, 2)/4));
    BOOST_REQUIRE((num_same + num_diff) == pow(num_elements, 2));

    /* if (num_same < (pow(num_elements, 2)/4)) { */
    /*     std::cout << "error: did not generate at least " */
    /*               << (pow(num_elements, 2)/4) */
    /*               << " matching elements"; */

    /* } */
    /* if ((num_same + num_diff) != pow(num_elements, 2)) { */
    /*     std::cout << "error: sum of same(" << num_same */
    /*               << ") and diff(" << num_diff << ") not " */
    /*               << pow(num_elements, 2) << " matching elements"; */
    /* } */
}

BOOST_AUTO_TEST_SUITE_END()
