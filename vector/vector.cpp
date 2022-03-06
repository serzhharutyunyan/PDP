#include "vector.h"
#include "iterator.h"

/* default constructor */
template<typename T>
Vector<T>::Vector() : len(0), elements(0), space(0), number(0) {}

/* fill constructor */
template<typename T>
Vector<T>::Vector(int s, T number) : len(s), elements(new T[s]), space(s), number(number) {
	for (int i = 0; i < len; ++i) {
		elements[i] = number;
    }
}

/* copy constructor */
template<typename T>
Vector<T>::Vector(const Vector & other) : len(other.len), elements(new T[other.len]) {
	for (int i = 0; i < other.len; ++i) {
		elements[i] = other.elements[i];
    }
}

/*
Assigns new contents to the container, replacing its current contents,
and modifying its size accordingly.
*/
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this == &other) {
        return *this;
    }

	if (other.len <= space) {
		for (int i = 0; i < other.len; ++i) {
			elements[i] = other.elements[i];
			len = other.len;
			return *this;
		}
	}

	T* p = new T[other.len];

	for (int i = 0; i < other.len; ++i) {
		p[i] = other.elements[i];
    }

	delete[] elements;
	size = other.len;
	space = other.len;
	elements = p;
	return *this;
}

/* Destructor */
template<typename T>
Vector<T>::~Vector() {
	delete[] elements;
}

/* Returns an iterator pointing to the first element in the vector */
template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
	return Vector<T>::iterator(&elements[0]);
}

/* Returns an iterator referring to the past-the-end element in the vector container */
template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
	return Vector<T>::iterator(&elements[len]);
}

/* Returns whether the vector is empty (i.e. whether its size is 0) */
template<typename T>
bool Vector<T>::empty() const {

	return (0 == len);
}

/* Returns the size of the storage space currently allocated for the vector */
template<typename T>
unsigned int Vector<T>::capacity() const {
	return space;
}

/*
Requests that the vector capacity be at least enough to contain n elements.
If val is specified, the new elements are initialized as copies of val,
otherwise, they are value-initialized.
*/
template<typename T>
void Vector<T>::reserve(int newMemory) {
	if (newMemory <= space) {
        return;
    }

	T* p = new T[newMemory];

	for (int i = 0; i < len; ++i) {
		p[i] = elements[i];
    }

	delete[] elements;
	elements = p;
	space = newMemory;
}

/* Resizes the container so that it contains n elements */
template<typename T>
void Vector<T>::resize(int newMemory, T val) {
	reserve(newMemory);

	for (int i = len; i < newMemory; ++i) {
		elements[i] = T();
    }

	len = newMemory;
}

/*
Returns the number of elements in the vector.
Member type size_type is an unsigned integral type.
*/
template<typename T>
unsigned int Vector<T>::size() const {
	return len;
}

/*
Adds a new element at the end of the vector,
after its current last element.
*/
template<typename T>
void Vector<T>::push_back(const T& data) {
	if (0 == space) {
		reserve(10);
    } else if (len == space) {
		reserve(2 * space);
    }

	elements[len] = data;
	++len;
}

/*
Removes the last element in the vector, effectively reducing the
container size by one. This destroys the removed element.
*/
template<typename T>
void Vector<T>::pop_back() {
    T *temp = new T[len - 1];
    for (int i = 0; i < len - 1; i++) {
        temp[i] = elements[i];
    }

    delete[] elements;
    elements = temp;
    --len;
}

/* Requests the container to reduce its capacity to fit its size. */
template<typename T>
void Vector<T>::shrink_to_fit() {
    (space > len) ? space = len : space;
}

/* Returns a reference to the element at position n in the vector container. */
template<typename T>
T &Vector<T>::operator[](int index) {
	return elements[index];
}