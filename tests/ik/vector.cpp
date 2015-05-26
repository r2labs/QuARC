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


const float get_off_x() { return off_x; }
const float get_off_y() { return off_y; }
const float get_off_z() { return off_z; }
