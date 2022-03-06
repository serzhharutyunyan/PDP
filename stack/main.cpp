#include <iostream>
#include "../vector/vector.cpp"
#include "stack.cpp"

int main() {

    Stack<int> s;
    s.push(5);
    s.push(51);
    s.push(8);
    s.push(12);
    s.push(20);

    std::cout << "Last element of stack: " << s.top() << std::endl;
    std::cout << "Size of stack: " << s.size() << std::endl;
    if (s.is_empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    s.pop();
    s.pop();
    return 0;
}