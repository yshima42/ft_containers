#include "avl_copy.hpp"
#include <iostream>

int main() {
    AVLTree<int> a;
    a.insert(2);
    std::cout << a.at(1)<< std::endl;

}