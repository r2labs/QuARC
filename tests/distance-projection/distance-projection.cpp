#include <math.h>
#include <iostream>

#include "ik/node.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(distance_projection) {

    const float node0_x = 0;
    const float node0_y = 0;
    const float node0_z = 0;

    const float node1_x = 1;
    const float node1_y = 1;
    const float node1_z = 1;

    ik::node* node0 = new ik::node(node0_x, node0_y, node0_z);
    ik::node* node1 = new ik::node(node1_x, node1_y, node1_z);

    const float calculated_distance = node0->distance_to(node1);

    const float actual_distance = sqrt(pow(node0_x - node1_x, 2) +
                                       pow(node0_y - node1_y, 2) +
                                       pow(node0_z - node1_z, 2));
    delete node0;
    delete node1;

    BOOST_CHECK(fabs(calculated_distance - actual_distance) < pow(10, -6));

    /* if () { */
    /*     std::cout << "calculated distance: " << calculated_distance << "\n" */
    /*               << "actual distance: " << actual_distance << "\n"; */
    /* } */
}
