#include "linked_list.h"

#ifndef ITERATOR_H
#define ITERATOR_H

    template<typename T>
    class List<T>::iterator {
        private:
            Node<T> *current;
        public:
            iterator(Node<T> *p) {
                this->current = p;
            }

            iterator& operator++() {
                current = current->next;
                return *this;
            }

            iterator& operator--() {
                current = current->prev;
                return *this;
            }

            iterator& operator++(int) {
                iterator temp = *this;
                Node<T> *ptr;
                ptr = ptr->next;
                return temp;
            }

            iterator& operator--(int) {
                iterator temp = *this;
                Node<T> *ptr;
                ptr = ptr->prev;
                return temp;
            }

            T& operator*() {
                return current->data;
            }

            bool operator==(const iterator& b) const {
                return current == b.current;
            }

            bool operator!=(const iterator& b) const {
                return current != b.current;
            }
};

#endif