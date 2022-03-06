#include <iostream>
#include "vector.cpp"

/* Print a vector */
template <typename T>
void print(Vector<T> a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
}

int main() {
    /* Initialization */
    Vector<int> v(10, 5);
    v.push_back(1);
    v.push_back(2);
    std::cout << "Capacity befor shrink_to_fit: " << v.capacity() << std::endl;
    std::cout << "Size vector: " << v.size() << std::endl;
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit: " << v.capacity() << std::endl;
    print(v);

    Vector<float> f(10, 4.2);
    Vector<float>::iterator it = f.begin();
    for(auto var : f) {
        std::cout << f[var] << "\t";
    }

    std::cout << std::endl;
    f.reserve(30);
    f.resize(15);
    std::cout << "Capacity befor reserve: " << f.capacity() << std::endl;
    std::cout << "Size befor resize: " << f.size() << std::endl;
    f.resize(10);
    f.pop_back();
    f.pop_back();
    f.pop_back();
    f.pop_back();
    std::cout << "Size vector: " << f.size() << std::endl;
    f.resize(0);

    if(f.empty()) {
        std::cout << "Vector is empty!!!" << std::endl;
    } else {
        std::cout << "Vector is not empty!!!" << std::endl;
    }

    Vector<int>::iterator it1 = v.begin();
    Vector<int>::iterator it2 = v.end();
    if (it1 == it2) {
        std::cout << "Equal!!!" << std::endl;
    } else {
        std::cout << "Not equal!!!" << std::endl;
    }

    std::cout << "Value of iterator: " << *it1 << std::endl;
    Vector<int>::iterator it3 = ++it2;

    /* Out size of vector */
    std::cout << "Value of iterator: " << *it3 << std::endl;

    return 0;
}