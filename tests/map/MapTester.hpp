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
  MapTester(ft::map<Key, T> &m, std::vector<ft::pair<Key, T> > &test_pairs)
      : _base_map(m), _base_const_map(m), _base_pairs(test_pairs) {}
  ~MapTester() {}
  void test_all() {
    test_constructor();
    test_assignment_operator();

    // element access
    test_subscript_operator();

    // capacity
    test_max_size();

    test_insert();
    test_clear();
    test_erase();
    test_swap();

    test_find();
    test_count();

    test_lower_bound();
    test_upper_bound();
    test_equal_range();

    test_get_allocator();
    test_key_comp();
    test_value_comp();
  }

 private:
  ft::map<Key, T> _base_map;
  ft::map<Key, T> const _base_const_map;
  std::vector<ft::pair<Key, T> > _base_pairs;

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
    std::cout << _base_pairs.size() << std::endl;
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m.insert(_base_pairs[i]);
    }
    print_map(m);

    ft::map<Key, T> m1(_base_map);
    typename ft::map<Key, T>::iterator it = ++_base_map.begin();
    m1.insert(it, _base_pairs[0]);
    m1.insert(it, _base_pairs[1]);
    m1.insert(it, _base_pairs[2]);
    m1.insert(it, _base_pairs[3]);
    m1.insert(it, _base_pairs[4]);
    print_map(m1);

    ft::map<Key, T> m2(_base_map);
    m2.insert(++m.begin(), --m.end());
    print_map(m2);
  }

  void test_clear() {
    std::cout << YELLOW << "< clear >" << RESET << std::endl;
    ft::map<Key, T> m(_base_map);
    print_map(m);
    m.clear();
    print_map(m);
  }

  void test_erase() {
    std::cout << YELLOW << "< erase >" << RESET << std::endl;
    ft::map<Key, T> m(_base_map);
    print_map(m);
    m.erase(1);
    print_map(m);
    m.erase(++m.begin());
    print_map(m);
    //これはセグフォ(stlも)
    // m.erase(m.end());
  }

  void test_swap() {
    std::cout << YELLOW << "< swap >" << RESET << std::endl;
    ft::map<Key, T> m1(_base_map);
    ft::map<Key, T> m2;
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m2.insert(_base_pairs[i]);
    }
    print_map(m1);
    print_map(m2);
    std::swap(m1, m2);
    print_map(m1);
    print_map(m2);
  }

  void test_find() {
    std::cout << YELLOW << "< find >" << RESET << std::endl;
    ft::map<Key, T> m;
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m.insert(_base_pairs[i]);
    }
    std::cout << m.find(_base_pairs[2].first)->second << std::endl;
  }

  void test_count() {
    std::cout << YELLOW << "< count >" << RESET << std::endl;
    ft::map<Key, T> m;
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m.insert(_base_pairs[i]);
    }
    std::cout << m.count(_base_pairs[2].first) << std::endl;
    // 適当なkey
    std::cout << m.count(9999) << std::endl;
  }

  void test_lower_bound() {
    std::cout << YELLOW << "< lower_bound >" << RESET << std::endl;
    ft::map<Key, T> m(_base_map);
    typename ft::map<Key, T>::iterator it = m.lower_bound(_base_pairs[1].first);
    std::cout << it->second << std::endl;

    ft::map<Key, T> m1(_base_map);
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m1.insert(_base_pairs[i]);
    }

    std::cout << m1.lower_bound(_base_pairs[1].first)->second << std::endl;
  }

  void test_upper_bound() {
    std::cout << YELLOW << "< upper_bound >" << RESET << std::endl;
    ft::map<Key, T> m(_base_map);
    typename ft::map<Key, T>::iterator it = m.upper_bound(_base_pairs[1].first);
    std::cout << it->second << std::endl;

    ft::map<Key, T> m1(_base_map);
    for (size_t i = 0; i < _base_pairs.size(); i++) {
      m1.insert(_base_pairs[i]);
    }

    std::cout << m1.lower_bound(_base_pairs[1].first)->second << std::endl;
  }

  void test_equal_range() {
    std::cout << YELLOW << "< equal_range >" << RESET << std::endl;
    ft::map<Key, T> m(_base_map);
    {
      ft::pair<typename ft::map<Key, T>::iterator,
               typename ft::map<Key, T>::iterator>
          p = m.equal_range(1);
      std::cout << p.first->first << p.second->first << std::endl;
      std::cout << "m[" << p.first->first << "] = " << p.first->second << '\n';

      if (p.second == m.find(2)) {
        std::cout << "end of equal_range (p.second) is one-past p.first\n";
      } else {
        std::cout << "unexpected; p.second expected to be one-past p.first\n";
      }
    }

    {
      ft::pair<typename ft::map<Key, T>::iterator,
               typename ft::map<Key, T>::iterator>
          pp = m.equal_range(-1);
      if (pp.first == m.begin()) {
        std::cout << "pp.first is iterator to first not-less than -1\n";
      } else {
        std::cout << "unexpected pp.first\n";
      }

      if (pp.second == m.begin()) {
        std::cout << "pp.second is iterator to first element greater-than -1\n";
      } else {
        std::cout << "unexpected pp.second\n";
      }
    }

    {
      ft::pair<typename ft::map<Key, T>::iterator,
               typename ft::map<Key, T>::iterator>
          ppp = m.equal_range(3);
      if (ppp.first == m.end()) {
        std::cout << "ppp.first is iterator to first not-less than 3\n";
      } else {
        std::cout << "unexpected ppp.first\n";
      }

      if (ppp.second == m.end()) {
        std::cout << "ppp.second is iterator to first element greater-than 3\n";
      } else {
        std::cout << "unexpected ppp.second\n";
      }
    }
  }

  void test_get_allocator() {
    std::cout << YELLOW << "< get_allocator >" << RESET << std::endl;
    std::cout << _base_map.get_allocator().max_size() << std::endl;
  }

  void test_key_comp() {
    std::cout << YELLOW << "< key_comp >" << RESET << std::endl;
    ft::map<Key, T> m;
    typename ft::map<Key, T>::key_compare comp = m.key_comp();
    std::cout << std::boolalpha
              << comp(_base_pairs[0].first, _base_pairs[1].first) << std::endl
              << comp(_base_pairs[1].first, _base_pairs[1].first) << std::endl
              << comp(_base_pairs[1].first, _base_pairs[0].first) << std::endl;
  }

  void test_value_comp() {
    std::cout << YELLOW << "< value_comp >" << RESET << std::endl;
    ft::map<Key, T> m;
    typename ft::map<Key, T>::value_compare comp = m.value_comp();
    std::cout << std::boolalpha << comp(_base_pairs[0], _base_pairs[1])
              << std::endl
              << comp(_base_pairs[1], _base_pairs[1]) << std::endl
              << comp(_base_pairs[1], _base_pairs[0]) << std::endl;
  }
};

#endif
