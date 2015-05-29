#include "position.hpp"

ik::position::position()
    : x(0), y(0), z(0) {}

ik::position::position(float x, float y, float z)
    : x(x), y(y), z(z) {}

ik::position::~position() { }

    return new ik::vector(this, pos->get_x() - get_x(),
                          pos->get_y() - get_y(),
                          pos->get_z() - get_z());
}

