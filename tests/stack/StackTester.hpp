#ifndef STACKTESTER_HPP
#define STACKTESTER_HPP

#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <string>

// constのテストも作る
template <class T, class Container = ft::vector<T> >
class StackTester {
 public:
  StackTester(ft::stack<T, Container> &stack)
      : _base_stack(stack), _base_const_stack(stack) {}
  ~StackTester() {}
  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_push();
    test_pop();
    test_relational_operators();
    test_iterate();
    std::cout << std::endl;
  }

 private:
  ft::stack<T, Container> _base_stack;
  ft::stack<T, Container> const _base_const_stack;

  void print_stack(ft::stack<T, Container> &stack,
                   const std::string &stack_name) {
    std::cout << stack_name << ": ";
    print_stack_info(stack);
    print_stack_elems(stack);
    std::cout << std::endl;
  }

  void print_stack_info(ft::stack<T, Container> &stack) {
    // size()テスト
    std::cout << std::endl << "size->" << stack.size() << " ";
  }

  void print_stack_elems(ft::stack<T, Container> &stack) {
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
    ft::stack<T, Container> a;
    print_stack(a, "a");

    ft::stack<T, Container> b(_base_stack);
    print_stack(b, "b(_base_stack)");
  }

  void test_assignment_operator() {
    std::cout << YELLOW << "< assignment operator >" << RESET << std::endl;
    ft::stack<T, Container> s;
    s = _base_stack;
    print_stack(s, "to no_size");

    ft::stack<T, Container> s1(s);
    s1 = _base_stack;
    print_stack(s1, "to s1(s))");

    ft::stack<T, Container> s2(_base_stack);
    s2 = _base_stack;
    print_stack(s2, "assigned identical stack");

    ft::stack<T, Container> s3 = _base_stack;
    print_stack(s3, "operator =");
  }

  void test_push() {
    std::cout << YELLOW << "< push >" << RESET << std::endl;

    ft::stack<T, Container> s1;
    ft::stack<T, Container> s2(_base_stack);

    for (size_t i = 0; i < s2.size() - 1; ++i) {
      s1.push(s2.top());
    }
    print_stack(s1, "push");
  }

  void test_pop() {
    std::cout << YELLOW << "< pop >" << RESET << std::endl;
    ft::stack<T, Container> stack(_base_stack);

    for (size_t i = 0; i < _base_stack.size() - 1; ++i) {
      stack.pop();
    }
    print_stack(stack, "pop");
  }

  void test_relational_operators() {
    std::cout << YELLOW << "< relational operators >" << RESET << std::endl;

    ft::stack<T, Container> s1(_base_stack);
    ft::stack<T, Container> s2(_base_stack);

    s2.pop();

    std::cout << std::boolalpha << "s1 == s1 : " << (s1 == s1) << std::endl
              << "s1 == s2 : " << (s1 == s2) << std::endl
              << "s1 != s1 : " << (s1 != s1) << std::endl
              << "s1 != s2 : " << (s1 != s2) << std::endl
              << "s1 < s1 : " << (s1 < s1) << std::endl
              << "s1 < s2 : " << (s1 < s2) << std::endl
              << "s2 < s1 : " << (s2 < s1) << std::endl
              << "s1 <= s1 : " << (s1 <= s1) << std::endl
              << "s1 <= s2 : " << (s1 <= s2) << std::endl
              << "s2 <= s1 : " << (s2 <= s1) << std::endl
              << "s1 > s1 : " << (s1 > s1) << std::endl
              << "s1 > s2 : " << (s1 > s2) << std::endl
              << "s2 > s1 : " << (s2 > s1) << std::endl
              << "s1 >= s1 : " << (s1 >= s1) << std::endl
              << "s1 >= s2 : " << (s1 >= s2) << std::endl
              << "s2 >= s1 : " << (s2 >= s1) << std::endl;
  }

  void test_iterate() {
    // iteratorは使用できない
    // _base_stack.begin();
    // _base_stack.end();
  }
};

#endif
