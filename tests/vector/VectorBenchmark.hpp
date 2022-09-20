#ifndef VECTORBENCHMARK_HPP
#define VECTORBENCHMARK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "test.hpp"


template <class T>
class VectorBenchmark {
 private:
  Timer time_;

  static const size_t LOOP_NUM = 10000;

 public:
  VectorBenchmark(ft::vector<T> &vec) : _base_vec(vec) {}
  ~VectorBenchmark() {}

  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_push_back_pop_back();
    test_assign();
    test_reserve_resize();
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
    ft::vector<T> v3(LOOP_NUM, 3);
    time_.stop_print();

    time_.start("constructor5");
    ft::vector<T> v4(LOOP_NUM, 'x');
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
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      vec.push_back(i);
    }
    time_.stop_print();

    time_.start("pop_back");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      vec.pop_back();
    }
    time_.stop_print();
  }

  void test_assign() {
    ft::vector<T> v;
    time_.start("assign");
    v.assign(LOOP_NUM, _base_vec.at(2));
    time_.stop_print();

    ft::vector<T> it_assign;
    time_.start("assign iterator");
    it_assign.assign(v.begin(), v.end());    
    time_.stop_print();
  }

  void test_reserve_resize() {
    ft::vector<T> vec;

    time_.start("reserve");
    vec.reserve(LOOP_NUM);
    time_.stop_print();

    time_.start("resize1");
    vec.resize(LOOP_NUM, _base_vec.at(1));
    time_.stop_print();

    time_.start("resize2");
    _base_vec.resize(LOOP_NUM, _base_vec.at(4));
    time_.stop_print();
  }

  

};

#endif
