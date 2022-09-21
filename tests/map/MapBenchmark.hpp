#ifndef MAPBENCHMARK_HPP
#define MAPBENCHMARK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "test.hpp"

template <class T>
class MapBenchmark {
 private:
  Timer time_;

 public:
  MapBenchmark(ft::map<T> &map) : _base_map(map) {}
  ~MapBenchmark() {}

  void test_all() {
    test_constructor();
    test_push_pop();
  }

 private:
  ft::map<T> _base_map;

  void test_constructor() {
    time_.start("constructor1");
    ft::map<T> a;
    time_.stop_print();

    time_.start("constructor2");
    ft::map<T> b(a);
    time_.stop_print();
  }

  void test_push_pop() {
    ft::map<T> map;

    time_.start("push_back");
    for (int i = 0; i < 10; ++i) {
      map.push(i);
    }
    time_.stop_print();

    time_.start("pop");
    for (int i = 0; i < 10; ++i) {
      map.pop();
    }
    time_.stop_print();
  }
};

#endif
