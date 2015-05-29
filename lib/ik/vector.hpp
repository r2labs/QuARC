#ifndef IK_VECTOR_HPP
#define IK_VECTOR_HPP

#include <string>

#include "position.hpp"

namespace ik {
    class position;

    class vector {
    public:
        vector();
        vector(const ik::position* origin,
               float off_x=0,
               float off_y=0,
               float off_z=0);

        ~vector();

        /* operators */
        ik::vector& operator=(const ik::vector& v);

        /* const functions */
        float magnitude(void) const;
        float dot(const ik::vector* v) const;
        float angle_between(const ik::vector* v) const;
        const std::string to_string(void) const;

        /* modifier functions */
        void normalize();

        /* getters */
        const ik::position* get_origin(void) const { return origin; }
        float get_off_x(void) const { return off_x; }
        float get_off_y(void) const { return off_y; }
        float get_off_z(void) const { return off_z; }

        /* setters */
        void set_origin(const ik::position* o);
        void set_off_x(float off_x) { this->off_x = off_x; }
        void set_off_y(float off_y) { this->off_y = off_y; }
        void set_off_z(float off_z) { this->off_z = off_z; }

    private:
        ik::position* origin;
        float off_x;
        float off_y;
        float off_z;
    };
}

#endif /* IK_VECTOR_HPP */
