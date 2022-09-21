#ifndef PAIRTESTER_HPP
#define PAIRTESTER_HPP

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <class T1, class T2>
class PairTester {
 public:
  PairTester(ft::pair<T1, T2> &pair)
      : _base_pair(pair), _base_const_pair(pair) {}
  ~PairTester() {}
  void test_all() {
    test_constructor();
    test_assignment();
    test_make_pair();
    test_operators();
  }

 private:
  ft::pair<T1, T2> _base_pair;
  ft::pair<T1, T2> const _base_const_pair;

  void print_pair(ft::pair<T1, T2> p) {
    std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
  }

  void test_constructor() {
    print_pair(_base_pair);

    ft::pair<T1, T2> p1;
    print_pair(p1);

    ft::pair<T1, T2> p2(_base_pair);
    print_pair(p2);
  }

  void test_assignment() {
    ft::pair<T1, T2> p;
    p = _base_pair;
    print_pair(p);
  }

  void test_make_pair() { print_pair(ft::make_pair<int, int>(10, 20)); }

  void test_operators() {
    ft::pair<int, int> p1(1, 1);
    ft::pair<int, int> p2(2, 1);
    ft::pair<int, int> p3(1, 2);

    std::cout << std::boolalpha 
              << "p1 == p1: " << (p1 == p1) << std::endl
              << "p1 == p2: " << (p1 == p2) << std::endl
              << "p1 == p3: " << (p1 == p3) << std::endl
              << "p1 != p1: " << (p1 != p1) << std::endl
              << "p1 != p2: " << (p1 != p2) << std::endl
              << "p1 != p3: " << (p1 != p3) << std::endl
              << "p1 <  p1: " << (p1 < p1) << std::endl
              << "p1 <  p2: " << (p1 < p2) << std::endl
              << "p1 <  p3: " << (p1 < p3) << std::endl
              << "p2 <  p1: " << (p2 < p1) << std::endl
              << "p3 <  p1: " << (p3 < p1) << std::endl
              << "p1 <= p1: " << (p1 <= p1) << std::endl
              << "p1 <= p2: " << (p1 <= p2) << std::endl
              << "p1 <= p3: " << (p1 <= p3) << std::endl
              << "p2 <= p1: " << (p2 <= p1) << std::endl
              << "p3 <= p1: " << (p3 <= p1) << std::endl
              << "p1 >  p1: " << (p1 > p1) << std::endl
              << "p1 >  p2: " << (p1 > p2) << std::endl
              << "p1 >  p3: " << (p1 > p3) << std::endl
              << "p2 >  p1: " << (p2 > p1) << std::endl
              << "p3 >  p1: " << (p3 > p1) << std::endl
              << "p1 >= p1: " << (p1 >= p1) << std::endl
              << "p1 >= p2: " << (p1 >= p2) << std::endl
              << "p1 >= p3: " << (p1 >= p3) << std::endl
              << "p2 >= p1: " << (p2 >= p1) << std::endl
              << "p3 >= p1: " << (p3 >= p1) << std::endl;
  }
};



#endif
