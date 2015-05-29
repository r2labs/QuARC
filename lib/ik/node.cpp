#include "node.hpp"
#include "position.hpp"

ik::node::node(float x, float y, float z, ik::node* next, ik::node* prev) :
    next(next), prev(prev) {

    pos = new ik::position(x, y, z);
}

ik::node::~node() {

    delete pos;
}

}
