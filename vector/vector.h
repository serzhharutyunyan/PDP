#ifndef VECTOR_H
#define VECTOR_H

    /*
    Here is implemented the vector.h file for the vector<T> class created by the user.
    */
    template<typename T>
    class Vector {
        public:
            Vector();
            Vector(int, T);
            Vector(const Vector&);
            Vector<T>& operator=(const Vector<T>&);
            ~Vector();
            class iterator;
            iterator begin();
            iterator end();
            bool empty() const;
            unsigned int capacity() const;
            void reserve(int);
            void resize(int, T val = T());
            unsigned int size() const;
            void shrink_to_fit();
            void push_back(const T& d);
            void pop_back();
            T& operator[](int i);
        private:
            unsigned int len;
            T* elements;
            unsigned int space;
            int number;
    };

#endif