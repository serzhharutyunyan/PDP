#include "node.h"
//#include "iterator.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

    template<typename T>
    class List {
        private:
            Node<T>* head;
            Node<T>* tail;
            unsigned int len;
        public:
            List();
            List(int, T);
            List(const List&);
            ~List();
            void push_back(const T&);
            void push_front(const T&);
            void pop_front();
            void pop_back();
            unsigned int size() const;
            bool empty() const;
            List<T>& operator=(const List<T>&);
            class iterator;
            iterator begin();
            iterator end();
            void insert(T, int);
    };

#endif