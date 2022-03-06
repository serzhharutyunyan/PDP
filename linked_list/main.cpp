#include <iostream>
#include "iterator.h"
#include "node.h"
#include "linked_list.cpp"

int main() {
    List<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(25);
    l.push_front(2);
    std::cout << l.size() << std::endl;
    auto it1 = l.begin();
    auto it2 = it1.operator++();

    for (auto it = l.begin(); it !=l.end(); it.operator++()) {
        std::cout << *it << std::endl;
    }

    std::cout << *it2 << std::endl;

    l.pop_back();
    l.pop_front();
    std::cout << l.size() << std::endl;

    if (l.empty()) {
        std::cout << "List is empty" << std::endl;
    } else {
        std::cout << "List is not empty" << std::endl;
    }

    return 0;
}