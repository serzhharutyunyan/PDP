#ifndef STACK_H
#define STACK_H

#include "../vector/vector.h"


    template<typename T>
    class Stack : private Vector<T> {
        public:
            Stack();
            void push(const T&);
            void pop();
            const T top();
            bool is_empty();
            int size();

        private:
            Vector<T> data;
    };
#endif