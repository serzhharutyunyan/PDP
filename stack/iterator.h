#include "vector.h"

#ifndef ITERATOR_H
#define IRERATOR_H

    template<typename T>
    class Vector<T>::iterator {
        public:
            iterator(T* p) : current(p) {}

            iterator& operator++() {
                current++;
                return *this;
            }

            iterator& operator++(int value) {
                iterator *temp = *this;
                current++;
                return *temp;
            }

            iterator& operator--() {
                current--;
                return *this;
            }

            iterator& operator--(int value) {
                iterator *temp = *this;
                current--;
                return *temp;
            }

            T& operator*() {
                return *current;
            }

            bool operator==(const iterator& b) const {
                return *current == *b.current;
            }

            bool operator!=(const iterator& b) const {
                return *current != *b.current;
            }

        private:
            T* current;
    };

#endif