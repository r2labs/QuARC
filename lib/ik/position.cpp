#include <sstream>

#include "position.hpp"

ik::position::position()
    : x(0), y(0), z(0) {}

ik::position::position(float x, float y, float z)
    : x(x), y(y), z(z) {}

ik::position::position(const ik::position& p) {

    this->x = p.get_x();
    this->y = p.get_y();
    this->z = p.get_z();
}

ik::position::~position() { }

const ik::vector* ik::position::vector_to(const ik::position* pos) const {

    auto x = pos->get_x() - get_x();
    auto y = pos->get_y() - get_y();
    auto z = pos->get_z() - get_z();

    return new ik::vector(new ik::position(get_x(), get_y(), get_z()), x, y, z);
}

const std::string ik::position::to_string() const {

    std::stringstream out;
    out << "("
        << get_x() << ","
        << get_y() << ","
        << get_z() << ")";

    return out.str();
}

/*! Assignment operator */
ik::position& ik::position::operator= (const ik::position& p) {

    set_x(p.get_x());
    set_y(p.get_y());
    set_z(p.get_z());
    return *this;
}

void ik::position::copy(const ik::position* p) {

    set_x(p->get_x());
    set_y(p->get_y());
    set_z(p->get_z());
}
