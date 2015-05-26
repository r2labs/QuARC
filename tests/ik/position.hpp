#ifndef IK_POSITION_HPP
#define IK_POSITION_HPP

#include "vector.hpp"

namespace ik {
    class vector;

    class position {
    public:
        position();
        position(float x, float y, float z);

        const ik::vector* vector_to(ik::position* p);

        const float get_x(void);
        const float get_y(void);
        const float get_z(void);

    private:
        float x;
        float y;
        float z;
    };
}
#endif /* IK_POSITION_HPP */
