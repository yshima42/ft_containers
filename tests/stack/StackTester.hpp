#ifndef STACKTESTER_HPP
#define STACKTESTER_HPP

#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>

// constのテストも作る
template <class T>
class StackTester {
 public:
  StackTester(ft::stack<T> &stack)
      : _base_stack(stack), _base_const_stack(stack) {}
  ~StackTester() {}
  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_pop();
  }

 private:
  ft::stack<T> _base_stack;
  ft::stack<T> const _base_const_stack;

  void print_stack(ft::stack<T> &stack, const std::string &stack_name) {
    std::cout << stack_name << ": ";
    print_stack_info(stack);
    print_stack_elems(stack);
    std::cout << std::endl;
  }

  void print_stack_info(ft::stack<T> &stack) {
    // size()テスト
    std::cout << std::endl << "size->" << stack.size() << " ";
  }

  void print_stack_elems(ft::stack<T> &stack) {
    std::cout << "elems->";
    // empty()テスト
    if (stack.empty())
      std::cout << "empty";
    else {
      std::cout << "top:" << stack.top();
    }
    std::cout << std::endl;
  }

  void test_constructor() {
    std::cout << YELLOW << "< constructor >" << RESET << std::endl;
    ft::stack<T> a;
    print_stack(a, "a");

    ft::stack<T> b(_base_stack);
    print_stack(b, "b(_base_stack)");
  }

  void test_assignment_operator() {
    std::cout << YELLOW << "< assignment operator >" << RESET << std::endl;
    ft::stack<T> s;
    s = _base_stack;
    print_stack(s, "to no_size");

    ft::stack<T> s1(s);
    s1 = _base_stack;
    print_stack(s1, "to s1(s))");

    ft::stack<T> s2(_base_stack);
    s2 = _base_stack;
    print_stack(s2, "assigned identical stack");
  }

  void test_pop() {
    std::cout << YELLOW << "< push_back, pop_back >" << RESET << std::endl;
    ft::stack<T> stack(_base_stack);

    for (size_t i = 0; i < _base_stack.size() - 1; ++i) {
      stack.pop();
    }
    print_stack(stack, "pop");
  }
};

#endif
