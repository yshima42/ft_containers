#ifndef StackBenchmarK_HPP
#define StackBenchmarK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "test.hpp"

template <class T>
class StackBenchmark {
 private:
  Timer time_;

 public:
  StackBenchmark(ft::stack<T> &stack) : _base_stack(stack) {}
  ~StackBenchmark() {}

  void test_all() {
    test_constructor();
    test_push_pop();
  }

 private:
  ft::stack<T> _base_stack;

  void test_constructor() {
    time_.start("constructor1");
    ft::stack<T> a;
    time_.stop_print();

    time_.start("constructor2");
    ft::stack<T> b(a);
    time_.stop_print();
  }

  void test_push_pop() {
    ft::stack<T> stack;

    time_.start("push_back");
    for (int i = 0; i < 10; ++i) {
      stack.push(i);
    }
    time_.stop_print();

    time_.start("pop");
    for (int i = 0; i < 10; ++i) {
      stack.pop();
    }
    time_.stop_print();
  }
};

#endif
