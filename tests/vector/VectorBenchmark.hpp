#ifndef VECTORBENCHMARK_HPP
#define VECTORBENCHMARK_HPP

#include <iostream>
#include <string>
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
    time_.start("constructor1");
    ft::vector<T> a;
    time_.stop_print();

    time_.start("constructor2");
    ft::vector<T> v(1);
    time_.stop_print();

    time_.start("constructor3");
    ft::vector<T> v2(10);
    time_.stop_print();

    time_.start("constructor4");
    ft::vector<T> v3(2, 3);
    time_.stop_print();

    time_.start("constructor5");
    ft::vector<T> v4(2, 'x');
    time_.stop_print();

    time_.start("constructor6");
    ft::vector<T> v5(_base_vec);
    time_.stop_print();

  }

  void test_assignment_operator() {
    ft::vector<T> v;
    time_.start("assign no_size");
    v = _base_vec;
    time_.stop_print();

    ft::vector<T> v1(20);
    time_.start("assign v1(20)");
    v1 = _base_vec;
    time_.stop_print();

    ft::vector<T> v2(v1);
    time_.start("assign identical");
    v2 = v1;
    time_.stop_print();
  }
 
  void test_push_back_pop_back() {

    ft::vector<T> vec;

    time_.start("push_back");
    for (int i = 0; i < 10; ++i) {
      vec.push_back(i);
    }
    time_.stop_print();

    time_.start("pop_back");
    for (int i = 0; i < 10; ++i) {
      vec.pop_back();
    }
    time_.stop_print();
  }
};

#endif
