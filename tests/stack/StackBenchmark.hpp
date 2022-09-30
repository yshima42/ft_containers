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
  static const size_t LOOP_NUM = 10000;
  
 public:
  StackBenchmark(ft::stack<T> &stack) : _base_stack(stack) {}
  ~StackBenchmark() {}

  void test_all() {
    test_constructor();
    test_push_pop();
    test_empty();
     test_size();
    // test_top();
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

    time_.start("push");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      stack.push(i);
    }
    time_.stop_print();

    time_.start("pop");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      stack.pop();
    }
    time_.stop_print();
  }

  void test_empty() {
    ft::stack<T> s1;
    time_.start("empty");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
    s1.empty();
    _base_stack.empty();
  }
    time_.stop_print();
  }

  void test_size() {
    ft::stack<T> s1;
    time_.start("size");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
    s1.size();
    _base_stack.size();
  }
    time_.stop_print();
  }

  void test_top() {
    ft::stack<T> s1;
    time_.start("top");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
    s1.top();
    _base_stack.top();
  }
    time_.stop_print();
 
  }

};

#endif
