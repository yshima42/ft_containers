#ifndef VECTORTESTER_HPP
#define VECTORTESTER_HPP

#include <iostream>

#include "test.hpp"

template <class T>
class VectorTester {
 public:
  VectorTester(ft::vector<T> &vec) : _base_vec(vec) {}
  ~VectorTester() {}
  void test_all() {
    test_constructor();
  }

 private:
  ft::vector<T> _base_vec;

  void print_vec(ft::vector<T> &vec, const std::string &vec_name) {
    std::cout << vec_name << ": ";
    print_vec_info(vec);
    print_vec_elems(vec);
    std::cout << std::endl;
  }

  void print_vec_info(ft::vector<T> &vec) {
    std::cout << std::endl << "size->" << vec.size() << " " <<
    "capacity->" << vec.capacity() << std::endl;
  }

  void print_vec_elems(ft::vector<T> &vec) {
    std::cout << "elems->";
    for (typename ft::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
      std::cout << *itr << " "; 
    std::cout << std::endl;
  }

  void test_constructor() {
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
    
  }

};

#endif
