#include <cassert>

#include "avl_tree.hpp"
#include "tree_node.hpp"

template <class T>
void print(T t) {
  std::cout << t << std::endl;
}

template <class T>
void test_print(std::string case_name, T output) {
  std::cout << case_name << ": " << output << std::endl;
}

void test_node() {
  ft::tree_node<int> n0(0);
  ft::tree_node<int> n1(10);
  ft::tree_node<int> n2(20);
  ft::tree_node<int> n3(30);
  ft::tree_node<int> n4(40);
  ft::tree_node<int> n5(50);
  ft::tree_node<int> n6(60);

  // test_print("balance()", n1.balance());
  assert(n1.balance() == 0);

  n1.connect_left(&n2);
  // test_print("balance()", n1.balance());
  assert(n1.balance() == 1);

  // leftについてる
  assert(n1.left_->value_ == n2.value_);
  assert(n2.parent_->value_ == n1.value_);

  // right
  n1.connect_right(&n3);
  assert(n1.right_->value_ == n3.value_);

  // parent
  n1.connect_parent(&n0, true);
  assert(n1.parent_->value_ == n0.value_);
  assert(n0.left_->value_ == n1.value_);

  // disconnect_parent
  assert(n0.left_->value_ == n1.value_);
  assert(n0.left_ != NULL);
  n1.disconnect_parent();
  assert(n1.parent_ == NULL);
  assert(n0.left_ == NULL);

  n2.disconnect_parent();
  n3.disconnect_parent();

  n3.connect_left(&n1);
  n1.connect_left(&n0);
  n1.connect_right(&n2);
  n3.connect_right(&n5);
  n5.connect_left(&n4);
  n5.connect_right(&n6);

  assert(n1.next_node()->value_ == n2.value_);
  assert(n2.next_node()->value_ == n3.value_);
  assert(n3.next_node()->value_ == n4.value_);
  assert(n4.next_node()->value_ == n5.value_);

  // n1.print_node();
  // n2.print_node();
  // n3.print_node();
  // n4.print_node();
  // n5.print_node();

  print("[OK]");
}

template <class T1, class T2>
void print_tree(ft::avl_tree<T1, T2> tree) {
  typename ft::avl_tree<T1, T2>::iterator it = tree.begin();
  for (; it != tree.end(); it++) it.base()->print_node();
}

void test_avl() {
  std::less<int> comp;
  std::allocator<ft::pair<const int, int> > alloc;
  ft::avl_tree<int, int> tree(comp, alloc);
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  assert(tree.size() == 5);

  ft::avl_tree<int, int> tree2(tree);
  assert(tree2.size() == 5);

  print_tree(tree);
}

// int main() {
//   test_node();
//   test_avl();
// }
