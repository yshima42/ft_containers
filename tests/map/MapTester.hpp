#ifndef MAPTESTER_HPP
#define MAPTESTER_HPP

#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

// constのテストも作る
// template <class T1, class T2>
// class MapTester {
//  public:
//   MapTester(ft::map<T1, T2> &map)
//       : _base_map(map), _base_const_map(map) {}
//   ~MapTester() {}
//   void test_all() {
//     // test_constructor();
//     // test_assignment_operator();
//     // test_pop();
//   }

//  private:
//   ft::map<T1, T2> _base_map;
//   ft::map<T1, T2> const _base_const_map;

//   // void print_map(ft::map<T> &map, const std::string &map_name) {
//   //   std::cout << map_name << ": ";
//   //   print_map_info(map);
//   //   print_map_elems(map);
//   //   std::cout << std::endl;
//   // }

//   // void print_map_info(ft::map<T> &map) {
//   //   // size()テスト
//   //   std::cout << std::endl << "size->" << map.size() << " ";
//   // }

//   // void print_map_elems(ft::map<T> &map) {
//   //   std::cout << "elems->";
//   //   // empty()テスト
//   //   if (map.empty())
//   //     std::cout << "empty";
//   //   else {
//   //     std::cout << "top:" << map.top();
//   //   }
//   //   std::cout << std::endl;
//   // }

//   // void test_constructor() {
//   //   std::cout << YELLOW << "< constructor >" << RESET << std::endl;
//   //   ft::map<T> a;
//   //   print_map(a, "a");

//   //   ft::map<T> b(_base_map);
//   //   print_map(b, "b(_base_map)");
//   // }

//   // void test_assignment_operator() {
//   //   std::cout << YELLOW << "< assignment operator >" << RESET <<
//   std::endl;
//   //   ft::map<T> s;
//   //   s = _base_map;
//   //   print_map(s, "to no_size");

//   //   ft::map<T> s1(s);
//   //   s1 = _base_map;
//   //   print_map(s1, "to s1(s))");

//   //   ft::map<T> s2(_base_map);
//   //   s2 = _base_map;
//   //   print_map(s2, "assigned identical map");
//   // }

//   // void test_pop() {
//   //   std::cout << YELLOW << "< push_back, pop_back >" << RESET <<
//   std::endl;
//   //   ft::map<T> map(_base_map);

//   //   for (size_t i = 0; i < _base_map.size() - 1; ++i) {
//   //     map.pop();
//   //   }
//   //   print_map(map, "pop");
//   // }
// };

#endif
