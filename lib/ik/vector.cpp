#include <math.h>

#include "vector.hpp"

ik::vector::vector() {}

ik::vector::vector(ik::position* origin, float off_x, float off_y, float off_z)
    : origin(origin), off_x(off_x), off_y(off_y), off_z(off_z) {}

const float ik::vector::magnitude() {
    return sqrt(pow(get_off_x(), 2) +
                pow(get_off_y(), 2) +
                pow(get_off_z(), 2));
}

const float ik::vector::get_off_x(void) { return off_x; }
const float ik::vector::get_off_y(void) { return off_y; }
const float ik::vector::get_off_z(void) { return off_z; }
