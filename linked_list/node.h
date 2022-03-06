#ifndef NODE_H
#define NODE_H

    /* This is an node.h file that represents Node the type that the user created. */
    template <typename T>
    struct Node {
        Node(const T& v = T(), Node* p = nullptr, Node* s = nullptr)
            : prev(p), next(s), data(v) {}
        Node* prev;
        Node* next;
        T data;
    };

#endif