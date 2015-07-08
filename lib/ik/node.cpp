#include "node.hpp"
#include "position.hpp"

ik::node::node(float x, float y, float z, ik::node* next, ik::node* prev) :
    next(next), prev(prev) {

    pos = new ik::position(x, y, z);
}

ik::node::~node() {

    delete pos;
}

float ik::node::distance_to(ik::node* n) const {

    const auto vec_to =  get_position()->vector_to(n->get_position());
    const auto mag = vec_to->magnitude();
    delete vec_to;
    return mag;
}
