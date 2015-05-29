#include <math.h>

#include "vector.hpp"

ik::vector::vector() {}

ik::vector::vector(const ik::position* origin,
                   float off_x,
                   float off_y,
                   float off_z)
    : off_x(off_x), off_y(off_y), off_z(off_z) {

    this->origin = new ik::position(*origin);
}

ik::vector::~vector() {
    delete origin;
}

float ik::vector::magnitude() const {
    return sqrt(pow(get_off_x(), 2) +
                pow(get_off_y(), 2) +
                pow(get_off_z(), 2));
}
