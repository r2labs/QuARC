#include <math.h>
#include <tgmath.h>

#include <sstream>

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

float ik::vector::dot(const ik::vector* v) const {

    return get_off_x()*v->get_off_x() +
        get_off_y()*v->get_off_y() +
        get_off_z()*v->get_off_z();
}

void ik::vector::normalize() {

    const auto mag = magnitude();
    set_off_x(get_off_x()/mag);
    set_off_y(get_off_y()/mag);
    set_off_z(get_off_z()/mag);
}

float ik::vector::angle_between(const ik::vector* v) const {

    return acos(dot(v)/(magnitude()*v->magnitude()));
}

int ik::vector::close_to(const ik::vector* v) const {

    const auto epsilon = pow(10.0 ,-6);

    if((fabs(get_off_x() - v->get_off_x()) < epsilon) &&
       (fabs(get_off_y() - v->get_off_y()) < epsilon) &&
       (fabs(get_off_z() - v->get_off_z()) < epsilon)) {
        return 1;
    }

    return 0;
}

const std::string ik::vector::to_string() const {

    std::stringstream out;
    out << "<" << origin->to_string() << ","
        << get_off_x() << ","
        << get_off_y() << ","
        << get_off_z() << ">";

    return out.str();
}

ik::vector& ik::vector::operator= (const ik::vector& v) {

    set_origin(v.get_origin());
    set_off_x(v.get_off_x());
    set_off_y(v.get_off_y());
    set_off_z(v.get_off_z());
    return *this;
}

void ik::vector::set_origin(const ik::position* o) {
    this->origin->copy(o);
}
