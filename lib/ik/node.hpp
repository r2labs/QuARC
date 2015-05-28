#ifndef IK_NODE_HPP
#define IK_NODE_HPP

#include "position.hpp"

namespace ik {
    class node {
    public:
        node(float x, float y, float z, ik::node* next=0, ik::node* prev=0);
        const ik::position* get_position();

    private:
        ik::position pos;
        ik::node* next;
        ik::node* prev;
    };
}

#endif /* IK_NODE_HPP */
