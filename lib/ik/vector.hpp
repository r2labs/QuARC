#ifndef IK_VECTOR_HPP
#define IK_VECTOR_HPP

#include "position.hpp"

namespace ik {
    class position;

    class vector {
    public:
        vector();
        vector(ik::position* origin, float off_x=0, float off_y=0, float off_z=0);

        const float magnitude(void);

        const float get_off_x(void);
        const float get_off_y(void);
        const float get_off_z(void);

    private:
        ik::position* origin;
        float off_x;
        float off_y;
        float off_z;
    };
}

#endif /* IK_VECTOR_HPP */
