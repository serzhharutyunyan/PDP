#include<iostream>
#include "binary_tree.cpp"

int main()
{
    BinaryTree<int> t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(1);
    t.insert(12);
    t.insert(10);
    t.insert(30);
    t.insert(60);

    std::cout << t.search(25)->data << std::endl;
    t.levelOrder();

    t.remove(60);
    t.remove(25);
    t.remove(30);
    t.inOrder();
}