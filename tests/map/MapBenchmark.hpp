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
  MapBenchmark(ft::map<T1, T2> &map, std::vector<ft::pair<T1, T2> > &test_pairs)
      : _base_map(map), _base_pairs(test_pairs) {}
  ~MapBenchmark() {}

  void test_all() {
    // iterator
    test_begin();
    test_end();
    test_rbegin();
    test_rend();

    // capacity
    test_empty();
    test_size();
    test_max_size();

    // modifiers
    test_operator();
    test_insert();
    test_erase();
    test_clear();
    test_swap();

    // operators
    test_find();
    test_count();
    test_lower_bound();
    test_upper_bound();
    test_equal_range();
  }

 private:
  ft::map<T1, T2> _base_map;
  std::vector<ft::pair<T1, T2> > _base_pairs;

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

  void test_empty() {
    ft::map<T1, T2> empty_map;
    time_.start("empty");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      empty_map.empty();
      _base_map.empty();
    }
    time_.stop_print();
  }

  void test_size() {
    time_.start("size");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      _base_map.size();
    }
    time_.stop_print();
  }

  void test_max_size() {
    time_.start("max_size");
    for (size_t i = 0; i < LOOP_NUM; ++i) {
      _base_map.max_size();
    }
    time_.stop_print();
  }

  void test_operator() {
    time_.start("operator");
    for (size_t i = 0; i < 20; ++i) {
      _base_map[i] = _base_pairs[2].second;
    }
    time_.stop_print();
  }

  void test_insert() {
    ft::map<T1, T2> m;
    time_.start("insert");
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m.insert(_base_pairs[i]);
    }
    time_.stop_print();
  }

  void test_erase() {
    ft::map<T1, T2> m(_base_map);
    time_.start("erase");
    for (size_t i = 0; i < LOOP_NUM; i++) {
        m.erase(i);
    }
    time_.stop_print();
  }

  void test_clear() {
    ft::map<T1, T2> m(_base_map);
    time_.start("clear");
    m.clear();
    time_.stop_print();
  }

  void test_swap() {
    ft::map<T1, T2> m1;
    ft::map<T1, T2> m2(_base_map);
    time_.start("swap");
    m2.swap(m2);
    time_.stop_print();
  }

  void test_find() {
    time_.start("find");
    for (size_t i = 0; i < LOOP_NUM; i++) {
        _base_map.find(i);
    }
    time_.stop_print();
  }

  void test_count() {
    time_.start("count");
    for (size_t i = 0; i < LOOP_NUM; i++) {
        _base_map.count(i);
    }
    time_.stop_print();
  }

  void test_lower_bound() {
    time_.start("lower_bound");
    for (size_t i = 0; i < LOOP_NUM; i++) {
        _base_map.lower_bound(i);
    }
    time_.stop_print();
 
  }

  void test_upper_bound() {
    time_.start("upper_bound");
    for (size_t i = 0; i < LOOP_NUM; i++) {
        _base_map.upper_bound(i);
    }
    time_.stop_print();
  }

  void test_equal_range() {
    time_.start("equal_range");
    for (size_t i = 0; i < LOOP_NUM; i++) {
        _base_map.equal_range(i);
    }
    time_.stop_print();
  }

};

#endif
