#ifndef MAPBENCHMARK_HPP
#define MAPBENCHMARK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "../test.hpp"

template <class T1, class T2>
class MapBenchmark {
 private:
  Timer time_;
  static const size_t LOOP_NUM = 10000;

 public:
  MapBenchmark(ft::map<T1, T2> &map) : _base_map(map) {}
  ~MapBenchmark() {}

  void test_all() {
    // iterator
    test_begin();
    test_end();
    test_rbegin();
    test_rend();

    // test_constructor();
    // test_push_pop();
  }

 private:
  ft::map<T1, T2> _base_map;

  void test_begin() {
    time_.start("begin");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      _base_map.begin();
    }
    time_.stop_print();
  }

  void test_end() {
    time_.start("end");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      _base_map.end();
    }
    time_.stop_print();
  }

  void test_rbegin() {
    time_.start("rbegin");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      _base_map.rbegin();
    }
    time_.stop_print();
  }

  void test_rend() {
    time_.start("rend");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      _base_map.rend();
    }
    time_.stop_print();
  }
  // void test_constructor() {
  //   time_.start("constructor1");
  //   ft::map<T1, T2> a;
  //   time_.stop_print();

  //   time_.start("constructor2");
  //   ft::map<T1, T2> b(a);
  //   time_.stop_print();
  // }

  // void test_push_pop() {
  //   ft::map<T1, T2> map;

  //   time_.start("push_back");
  //   for (int i = 0; i < 10; ++i) {
  //     map.push(i);
  //   }
  //   time_.stop_print();

  //   time_.start("pop");
  //   for (int i = 0; i < 10; ++i) {
  //     map.pop();
  //   }
  //   time_.stop_print();
  // }
};

#endif
