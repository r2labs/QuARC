#ifndef IK_POSITION_HPP
#define IK_POSITION_HPP

#include "vector.hpp"

namespace ik {
    class vector;

    class position {
    public:
        position();
        position(float x, float y, float z);
        position(const ik::position&);
        ~position();

        const ik::vector* vector_to(const ik::position* p) const;

        float get_x(void) const { return this->x; }
        float get_y(void) const { return this->y; }
        float get_z(void) const { return this->z; }

        void set_x(float x) { this->x = x; }
        void set_y(float y) { this->y = y; }
        void set_z(float z) { this->z = z; }

        ik::position& operator= (ik::position& p);

    private:
        float x;
        float y;
        float z;
    };
}
#endif /* IK_POSITION_HPP */
