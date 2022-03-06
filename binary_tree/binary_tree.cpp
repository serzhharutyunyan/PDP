#include <iostream>
#include <queue>

#include "binary_tree.h"

/* Deleted all binary tree (private metod) */
template <typename T>
Node<T>* BinaryTree<T>::makeEmpty(Node<T>* tree) {
    if (nullptr == tree) {
        return nullptr;
    }

    makeEmpty(tree->left);
    makeEmpty(tree->right);
    delete tree;
    return nullptr;
}

/* Added elemen into binary tree (private metod) */
template <typename T>
Node<T>* BinaryTree<T>::insert(T value, Node<T>* tree) {
    if (nullptr == tree) {
        tree = new Node<T>;
        tree->data = value;
        tree->left = tree->right = nullptr;
    } else if (value < tree->data) {
        tree->left = insert(value, tree->left);
    } else if (value > tree->data) {
        tree->right = insert(value, tree->right);
    }

    return tree;
}

/* Compare and find min element from tow node (private metod) */
template <typename T>
Node<T>* BinaryTree<T>::findMin(Node<T>* tree) {
    if (nullptr == tree) {
        return NULL;
    } else if (nullptr == tree->left) {
        return tree;
    } else {
        return findMin(tree->left);
    }
}

/* Compare and find max element from tow node (private metod) */
template <typename T>
Node<T>* BinaryTree<T>::findMax(Node<T>* tree) {
    if(nullptr == tree) {
        return nullptr;
    } else if (nullptr == tree->right) {
        return tree;
    } else {
        return findMax(tree->right);
    }
}

/* Deleted element out of binary tree by value (private metod) */
template <typename T>
Node<T>* BinaryTree<T>::remove(T value, Node<T>* tree) {
    Node<T>* newtree;
    if (nullptr == tree) {
        return NULL;
    } else if (value < tree->data) {
        tree->left = remove(value, tree->left);
    } else if (value > tree->data) {
        tree->right = remove(value, tree->right);
    } else if(tree->left && tree->right) {
        newtree = findMin(tree->right);
        tree->data = tree->data;
        tree->right = remove(tree->data, tree->right);
    } else {
        newtree = tree;
        if (nullptr == tree->left) {
            tree = tree->right;
        } else if (nullptr == tree->right) {
            tree = tree->left;
        }

        delete newtree;
    }

    return tree;
}

/* This metod printed all elements for binary tree from layer (private metod) */
template <typename T>
void BinaryTree<T>::inOrder(Node<T>* tree) {
    if (nullptr == tree) {
        return;
    }

    inOrder(tree->left);
    std::cout << tree->data << " ";
    inOrder(tree->right);
}

/*
This metod printed all elements for binary tree
from left to right (private metod)
*/
template <typename T>
void BinaryTree<T>::levelOrder(Node<T>* tree) {
    std::queue<Node<T>*> queue;
    queue.push(root);
    while (true) {
        int len = queue.size();
        if (0 == len) {
	        return;
        }

        int i = 0;
        while (i < len) {
    	    Node<T>* temp = queue.front();
	        std::cout << temp->data << " ";
            if (nullptr != temp->left) {
                queue.push(temp->left);
            }

            if(nullptr != temp->right) {
                queue.push(temp->right);
            }

            queue.pop();
            i++;
        }
        std::cout << std::endl;
    }
}

/* Return element out of binary tree by value (private metod) */
template <typename T>
Node<T>* BinaryTree<T>::getElement(Node<T>* tree, T value) {
    if (nullptr == tree) {
        return nullptr;
    } else if (value < tree->data) {
        return getElement(tree->left, value);
    } else if (value > tree->data) {
        return getElement(tree->right, value);
    } else {
        return tree;
    }
}

/* Constructor */
template <typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

/* Destructor */
template <typename T>
BinaryTree<T>::~BinaryTree() {
    root = makeEmpty(root);
}

/*
Public metod used private insert metod
and added element into binary tree
*/
template <typename T>
void BinaryTree<T>::insert(T value){
    root = insert(value, root);
}

/*
Public metod used private remove metod
and remove element of binary tree by value
*/
template <typename T>
void BinaryTree<T>::remove(T value) {
    root = remove(value, root);
}

/*
Public metod used private inOrder metod
and printed all elements of binary tree from left to right
*/
template <typename T>
void BinaryTree<T>::inOrder() {
    inOrder(root);
    std::cout << std::endl;
}

/*
Public metod used private levrlOrder metod
and printed elements of tree by layer
*/
template <typename T>
void BinaryTree<T>::levelOrder() {
    levelOrder(root);
    std::cout << std::endl;
}

/*
Public metod used private getElement metod and
return element from binary tree by value
*/
template <typename T>
Node<T> *BinaryTree<T>::search(T value) {
    Node<T> *a = getElement(root, value);
    return a;
}