#include "node.hpp"
#include "position.hpp"

ik::node::node(float x, float y, float z, ik::node* next, ik::node* prev) :
    next(next), prev(prev) {

    pos = ik::position(x, y, z);
}

const ik::position* ik::node::get_position() {

    return &pos;
}
