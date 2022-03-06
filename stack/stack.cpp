#include "stack.h"

    template<typename T>
    Stack<T>::Stack() {}

    template <typename T>
    void Stack<T>::push(const T& elem) {
        data.push_back(elem);
    }

    template <typename T>
    void Stack<T>::pop() {
        if (data.empty()) {
            data.pop_back();
        }
    }

    template<typename T>
    const T Stack<T>::top() {
        return  data[data.size() - 1];
    }

    template<typename T>
    bool Stack<T>::is_empty() {
        return data.empty();
    }

    template<typename T>
    int Stack<T>::size() {
        return data.size();
    }