#ifndef IK_VECTOR_HPP
#define IK_VECTOR_HPP

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

        float magnitude(void) const;

        float get_off_x(void) const { return off_x; }
        float get_off_y(void) const { return off_y; }
        float get_off_z(void) const { return off_z; }

    private:
        ik::position* origin;
        float off_x;
        float off_y;
        float off_z;
    };
}

#endif /* IK_VECTOR_HPP */
