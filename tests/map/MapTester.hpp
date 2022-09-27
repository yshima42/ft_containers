#ifndef MAPTESTER_HPP
#define MAPTESTER_HPP

#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

// constのテストも作る
template <class Key, class T>
class MapTester {
 public:
  MapTester(ft::map<Key, T> &m) : _base_map(m), _base_const_map(m) {(void)m;}
  ~MapTester() {}
  void test_all() {
    test_constructor();
    // test_assignment_operator();
    // test_pop();
  }

 private:
  ft::map<Key, T> _base_map;
  ft::map<Key, T> const _base_const_map;

  void print_pair(ft::pair<Key, T> p) {
    std::cout << "(" << p.first << ", " << p.second << ")";
  }

  void print_map(ft::map<Key, T> &m) {
    std::cout << std::boolalpha << "size = " << m.size() << ", empty = " << m.empty() <<
    ", elems: ";
    typename ft::map<Key, T>::iterator iter = m.begin();
    for (size_t i = 0; i < m.size(); i++) {
      std::cout << "[" << i << "] = ";
      print_pair(*iter);
      ++iter;
      if (i < m.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << std::endl;
  }

  // void print_map_info(ft::map<T> &map) {
  //   // size()テスト
  //   std::cout << std::endl << "size->" << map.size() << " ";
  // }

  // void print_map_elems(ft::map<T> &map) {
  //   std::cout << "elems->";
  //   // empty()テスト
  //   if (map.empty())
  //     std::cout << "empty";
  //   else {
  //     std::cout << "top:" << map.top();
  //   }
  //   std::cout << std::endl;
  // }

  void test_constructor() {
    std::cout << YELLOW << "< constructor >" << RESET << std::endl;
    ft::map<Key, T> m;
    print_map(m);

    typename ft::map<Key, T>::iterator it_begin = _base_map.begin();
    typename ft::map<Key, T>::iterator it_end = _base_map.end();
    it_end--;
    ft::map<Key, T> itr_map(it_begin, it_end);
    print_map(itr_map);

    ft::map<Key, T> copy_map(_base_map);
    print_map(copy_map);

  }

  // void test_assignment_operator() {
  //   std::cout << YELLOW << "< assignment operator >" << RESET << std::endl;
  //   ft::map<T> s;
  //   s = _base_map;
  //   print_map(s, "to no_size");

  //   ft::map<T> s1(s);
  //   s1 = _base_map;
  //   print_map(s1, "to s1(s))");

  //   ft::map<T> s2(_base_map);
  //   s2 = _base_map;
  //   print_map(s2, "assigned identical map");
  // }

  // void test_pop() {
  //   std::cout << YELLOW << "< push_back, pop_back >" << RESET << std::endl;
  //   ft::map<T> map(_base_map);

  //   for (size_t i = 0; i < _base_map.size() - 1; ++i) {
  //     map.pop();
  //   }
  //   print_map(map, "pop");
  // }
};

#endif
