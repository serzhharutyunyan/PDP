#ifndef NODE_H
#define NODE_H

    /*
    Here is implemented the node.h file for the
    Node<T> struct created by the user
    */
    template <typename T>
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

#endif