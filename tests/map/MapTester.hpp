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
  MapTester(ft::map<Key, T> &m, ft::pair<Key, T> test_pairs[]) : _base_map(m), _base_const_map(m), _test_pairs(test_pairs){
  
  }
  ~MapTester() {}
  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_max_size();
    test_subscript_operator();
    test_insert();
    test_erase();
  }

 private:
  ft::map<Key, T> _base_map;
  ft::map<Key, T> const _base_const_map;
  ft::pair<Key, T> *_test_pairs;

  void print_pair(ft::pair<Key, T> p) {
    std::cout << "(" << p.first << ", " << p.second << ")";
  }

  void print_map(ft::map<Key, T> &m) {
    std::cout << std::boolalpha << "size = " << m.size()
              << ", empty = " << m.empty() << ", elems: ";
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

  void test_assignment_operator() {
    std::cout << YELLOW << "< assignment operator >" << RESET << std::endl;
    ft::map<Key, T> m;
    m = _base_map;
    print_map(m);

    ft::map<Key, T> m1(m);
    m1 = _base_map;
    print_map(m1);

    ft::map<Key, T> m2(_base_map);
    m2 = _base_map;
    print_map(m2);
  }

  void test_max_size() {
    std::cout << YELLOW << "< max_size() >" << RESET << std::endl;
    ft::map<Key, T> m;
    std::cout << m.max_size() << std::endl;
  }

  void test_subscript_operator() {
    std::cout << YELLOW << "< operator[] >" << RESET << std::endl;
    ft::map<Key, T> m(++_base_map.begin(), --_base_map.end());
    std::cout << m[1] << std::endl;
    m[1] = "cccc";
    std::cout << m[1] << std::endl;
  }

  void test_insert() {
    std::cout << YELLOW << "< insert >" << RESET << std::endl;
    ft::map<Key, T> m;
    for (size_t i = 0; i < 5; i++) {
    m.insert(_test_pairs[i]); }
    print_map(m);

    ft::map<Key, T> m1(_base_map);
    typename ft::map<Key, T>::iterator it = ++_base_map.begin();
    m1.insert(it, _test_pairs[0]); 
    m1.insert(it, _test_pairs[1]); 
    m1.insert(it, _test_pairs[2]); 
    m1.insert(it, _test_pairs[3]); 
    m1.insert(it, _test_pairs[4]); 
    print_map(m1);

    ft::map<Key, T> m2(_base_map);
    m2.insert(++m.begin(), --m.end());
    print_map(m2);

  }

  void test_erase() {
    // std::cout << YELLOW << "< erase >" << RESET << std::endl;
    // ft::map<Key, T> m(_base_map);
    // m.erase(10);
    // print_map(m);

  }

};

#endif
