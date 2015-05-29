#include "position.hpp"

ik::position::position()
    : x(0), y(0), z(0) {}

ik::position::position(const float x, const float y, const float z)
    : x(x), y(y), z(z) {}

const ik::vector* ik::position::vector_to(ik::position* pos) {

    return new ik::vector(this, pos->get_x() - get_x(),
                          pos->get_y() - get_y(),
                          pos->get_z() - get_z());
}

