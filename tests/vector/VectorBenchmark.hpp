#ifndef VECTORBENCHMARK_HPP
#define VECTORBENCHMARK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "test.hpp"

template <class T>
class VectorBenchmark {
 private:
  Timer time_;

 public:

  VectorBenchmark(ft::vector<T> &vec) : _base_vec(vec) {}
  ~VectorBenchmark() {}

  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_push_back_pop_back();
  }

 private:
  ft::vector<T> _base_vec;

  void test_constructor() {
    time_.start("constructor");
    ft::vector<int> a(2, 3);
    time_.stop_print();
  }

  void test_assignment_operator() {
  }
 
  void test_push_back_pop_back() {
  }
};

#endif
