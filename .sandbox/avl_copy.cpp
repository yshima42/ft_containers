#include "avl_copy.hpp"

#include <iostream>

int main() {
  AVL<int> a;
  a.insert(100);
  a.insert(3);
  a.insert(4);
  a.insert(5);
  a.insert(6);
  a.insert(7);
  a.inorder();
  // std::cout << a.search(2)<< std::endl;
}