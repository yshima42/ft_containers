#ifndef VECTORBENCHMARK_HPP
#define VECTORBENCHMARK_HPP

#include <iostream>
#include <string>
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
    std::cout << YELLOW << "< constructor >" << RESET << std::endl;
    ft::vector<T> a;
    print_vec(a, "a");

    ft::vector<T> v(1);
    print_vec(v, "v(1)");

    ft::vector<T> v2(10);
    print_vec(v2, "v2(10)");

    ft::vector<T> v3(2, 3);
    print_vec(v3, "v3(2, 3)");

    ft::vector<T> v4(2, 'x');
    print_vec(v4, "v4(2, 'x')");

    ft::vector<T> v5(_base_vec);
    print_vec(v5, "v5(_base_vec)");

    // need to add enable_if to move this test
    // ft::vector<int> v6(v4.begin(), v4.end());
    // std::cout << v6.size() << std::endl;
  }

  void test_assignment_operator() {
    ft::vector<T> v;
    v = _base_vec;
    print_vec(v, "to no_size");

    ft::vector<T> v1(20);
    v1 = _base_vec;
    print_vec(v, "to v1(20)");

    ft::vector<T> v2(v1);
    v2 = v1;
    print_vec(v, "assigned identical vec");
  }

  //skip for now
  //void test_assign() {
  //  ft::vector<char> characters;
  //  characters.assign(5, 'a');
  //  print_vec(characters, "characters.assign(5, 'a')");

  //}
  
  void test_push_back_pop_back() {
    ft::vector<T> vec;
    for (int i = 0; i < 10; ++i) {
      vec.push_back(i);
    }
    print_vec(vec, "0 to 9");

    for (int i = 0; i < 10; ++i) {
      vec.pop_back();
      print_vec(vec, "pop_back");
    }
  }

};

#endif
