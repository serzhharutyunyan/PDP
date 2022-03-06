#include "node.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

    /*
    Here is implemented the binary_tree.h file for the
    BinaryTree<T> class created by the user.
    */
    template <typename T>
    class BinaryTree {
        private:
            Node<T> *root;
            Node<T> *makeEmpty(Node<T> *);
            Node<T> *insert(T, Node<T> *);
            Node<T> *findMin(Node<T> *);
            Node<T> *findMax(Node<T> *);
            Node<T> *remove(T, Node<T> *);
            void inOrder(Node<T> *);
            void levelOrder(Node<T>*);
            Node<T> *getElement(Node<T> *, T);
        public:
            BinaryTree();
            ~BinaryTree();
            void insert(T);
            void remove(T);
            void inOrder();
            void levelOrder();
            Node<T> *search(T);
    };

#endif