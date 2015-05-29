#ifndef IK_POSITION_HPP
#define IK_POSITION_HPP

#include "vector.hpp"

namespace ik {
    class vector;

    class position {
    public:
        position();
        position(float x, float y, float z);
        ~position();

        ik::vector* vector_to(ik::position* p);

        float get_x(void) { return this->x; }
        float get_y(void) { return this->y; }
        float get_z(void) { return this->z; }

        void set_x(float x) { this->x = x; }
        void set_y(float y) { this->y = y; }
        void set_z(float z) { this->z = z; }

    private:
        float x;
        float y;
        float z;
    };
}
#endif /* IK_POSITION_HPP */
