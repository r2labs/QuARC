#ifndef IK_NODE_HPP
#define IK_NODE_HPP

#include "position.hpp"

namespace ik {
    class node {
    public:
        node(float x, float y, float z, ik::node* next=0, ik::node* prev=0);
        ~node();

        float distance_to(ik::node* n) const;

        void set_position(ik::position* p) { pos = p; }
        void set_next(ik::node* n) { next = n; }
        void set_prev(ik::node* n) { prev = n; }

        const ik::position* get_position() const { return pos; }
        const ik::node* get_next() const { return next; }
        const ik::node* get_prev() const { return prev; }

    private:
        ik::position* pos;
        ik::node* next;
        ik::node* prev;
    };
}

#endif /* IK_NODE_HPP */
