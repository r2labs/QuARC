#ifndef IK_NODE_HPP
#define IK_NODE_HPP

#include "position.hpp"

namespace ik {
    class node {
    public:
        node(float x, float y, float z, ik::node* next=0, ik::node* prev=0);
        ~node();

        void set_position(ik::position* p) { pos = p; }
        void set_next(ik::node* n) { next = n; }
        void set_prev(ik::node* n) { prev = n; }

        ik::position* get_position() { return pos; }
        ik::node* get_next() { return next; }
        ik::node* get_prev() { return prev; }

    private:
        ik::position* pos;
        ik::node* next;
        ik::node* prev;
    };
}

#endif /* IK_NODE_HPP */
