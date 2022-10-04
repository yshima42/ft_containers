#ifndef VECTORTESTER_HPP
#define VECTORTESTER_HPP

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

// constのテストも作る
template <class T>
class VectorTester {
 public:
  VectorTester(ft::vector<T> &vec) : _base_vec(vec), _base_const_vec(vec) {}
  ~VectorTester() {}
  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_assign();
    test_at();
    test_operators();
    test_push_back_pop_back();
    test_reserve_resize();
    test_insert();
    test_iterator();
    test_erase();
    test_swap();
    test_get_allocator();
    test_small_funcs();
    test_relational_operator();
  }

 private:
  ft::vector<T> _base_vec;
  ft::vector<T> const _base_const_vec;

  void print_vec(ft::vector<T> &vec, const std::string &vec_name) {
    std::cout << vec_name << ": ";
    print_vec_info(vec);
    print_vec_elems(vec);
    std::cout << std::endl;
  }

  void print_vec_info(ft::vector<T> &vec) {
    // size()テスト
    std::cout << std::endl
              << "size->" << vec.size() << " " <<
        // capacity()テスト
        "capacity->" << vec.capacity() << std::endl;
  }

  void print_vec_elems(ft::vector<T> &vec) {
    std::cout << "elems->";
    // empty()テスト
    if (vec.empty()) std::cout << "empty";
    // iteratorテスト
    for (typename ft::vector<T>::iterator iter = vec.begin(); iter != vec.end();
         ++iter)
      std::cout << *iter << " ";
    std::cout << std::endl;
  }

  void test_constructor() {
    std::cout << YELLOW << "< constructor >" << RESET << std::endl;
    ft::vector<T> a;
    print_vec(a, "a");

    ft::vector<T> v(1);
    print_vec(v, "v(1)");

    ft::vector<T> v2(10);
    print_vec(v2, "v2(10)");

    ft::vector<T> v3(2, _base_vec.at(1));
    ft::vector<T> v3_c(2, _base_const_vec.at(1));
    print_vec(v3, "v3(2, _base_vec.at(1))");

    ft::vector<T> v5(_base_vec);
    ft::vector<T> v5_c(_base_const_vec);
    print_vec(v5, "v5(_base_vec)");

    v5.clear();
    print_vec(v5, "v5.clear");

    // need to add enable_if to move this test
    ft::vector<T> v6(v3.begin(), v3.end());
    print_vec(v6, "v6(v4.begin(), v4.end())");
  }

  void test_assignment_operator() {
    std::cout << YELLOW << "< assignment operator >" << RESET << std::endl;
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

  void test_assign() {
    std::cout << YELLOW << "< assign >" << RESET << std::endl;
    ft::vector<T> v;
    v.assign(5, _base_vec.at(2));
    print_vec(v, "v.assign(5, _base_vec.at(2))");

    ft::vector<T> it_assign;
    it_assign.assign(v.begin(), v.end());
    print_vec(it_assign, "it_assign.assign(v.begin(), v.end())");
  }

  void test_at() {
    std::cout << YELLOW << "< at >" << RESET << std::endl;
    try {
      std::cout << _base_vec.at(0) << std::endl;
      std::cout << _base_vec.at(3) << std::endl;
      std::cout << _base_vec.at(6) << std::endl;
    } catch (std::out_of_range &e) {
      std::cout << e.what() << std::endl;
    }
  }

  void test_operators() {
    std::cout << YELLOW << "< operators >" << RESET << std::endl;
    try {
      std::cout << _base_vec[0] << std::endl;
      std::cout << _base_vec[3] << std::endl;
      // std::cout << _base_vec[6] << std::endl;
    } catch (std::out_of_range &e) {
      std::cout << e.what() << std::endl;
    }
  }

  void test_push_back_pop_back() {
    std::cout << YELLOW << "< push_back, pop_back >" << RESET << std::endl;
    ft::vector<T> vec;
    for (size_t i = 0; i < _base_vec.size(); ++i) {
      vec.push_back(_base_vec.at(i));
    }
    print_vec(vec, "push_back");

    for (size_t i = 0; i < _base_vec.size() - 1; ++i) {
      vec.pop_back();
      print_vec(vec, "pop_back");
    }
  }

  void test_reserve_resize() {
    std::cout << YELLOW << "< reserve, resize >" << RESET << std::endl;
    ft::vector<T> vec;
    vec.reserve(10);
    print_vec(vec, "reserve(10)");

    vec.resize(15, _base_vec.at(1));
    print_vec(vec, "resize(15)");

    try {
      std::cout << "reserve exception" << std::endl;
      vec.reserve(4611686018427387904);
    } catch (std::length_error &e) {
      std::cout << e.what() << std::endl;
    }
  }

  void test_insert() {
    std::cout << YELLOW << "< insert >" << RESET << std::endl;
    ft::vector<T> vec(_base_vec);
    ft::vector<T> vec2(_base_vec);
    vec2.insert((vec2.begin() + 1), vec.at(2));
    print_vec(vec2, "vec2.insert((vec.begin() + 1), vec.at(2))");

    vec.insert(vec.begin(), 5, vec2.at(2));
    print_vec(vec, "vec.insert(vec.begin(), 5, vec.back())");

    vec.insert(vec.begin() + 3, vec2.begin() + 1, vec2.end() - 1);
    print_vec(vec,
              "vec.insert(vec.begin() + 3, vec.begin() + 1, vec.end() - 1)");
  
  }

  void test_iterator() {
    std::cout << YELLOW << "< iterator >" << RESET << std::endl;
    std::cout << *(_base_vec.begin()) << std::endl;
    std::cout << *(_base_const_vec.begin()) << std::endl;
    std::cout << *(_base_vec.begin() + 1) << std::endl;
    std::cout << *(_base_const_vec.begin() + 1) << std::endl;
    std::cout << *(_base_vec.begin() + 2) << std::endl;
    std::cout << *(_base_vec.end() - 1) << std::endl;
    std::cout << *(_base_const_vec.end() - 1) << std::endl;
    std::cout << *(_base_vec.end() - 2) << std::endl;
    std::cout << *(_base_vec.rbegin()) << std::endl;
    std::cout << *(_base_const_vec.rbegin()) << std::endl;
    std::cout << *(_base_vec.rbegin() + 1) << std::endl;
    std::cout << *(_base_const_vec.rbegin() + 1) << std::endl;
    std::cout << *(_base_vec.rbegin() + 2) << std::endl;
    std::cout << *(_base_vec.rend() - 1) << std::endl;
    std::cout << *(_base_const_vec.rend() - 1) << std::endl;
    std::cout << *(_base_vec.rend() - 2) << std::endl;

    typename ft::vector<T>::iterator it = _base_vec.begin();
    while (it < _base_vec.end()) {
      std::cout << *(it++) << std::endl;
    }
    it--;
    while (it > _base_vec.begin()) {
      std::cout << *(it--) << std::endl;
    }
    while (it < _base_vec.end() - 1) {
      std::cout << *(++it) << std::endl;
    }
    while (it > _base_vec.begin()) {
      std::cout << *(--it) << std::endl;
    }

    typename ft::vector<T>::iterator first = _base_vec.begin();
    typename ft::vector<T>::iterator second = _base_vec.begin() + 1;
    std::cout << std::boolalpha << "first  < first  : " << (first < first)
              << std::endl
              << "first  < second : " << (first < second) << std::endl
              << "first  > first  : " << (first > first) << std::endl
              << "second > first  : " << (second > first) << std::endl
              << "first <= first  : " << (first <= first) << std::endl
              << "first <= second : " << (first <= second) << std::endl
              << "second<= first  : " << (second <= first) << std::endl
              << "first >= first  : " << (first >= first) << std::endl
              << "first >= second : " << (first >= second) << std::endl
              << "second>= first  : " << (second >= first) << std::endl;

    std::cout << second[2] << std::endl;
  }

  void test_erase() {
    std::cout << YELLOW << "< erase >" << RESET << std::endl;
    ft::vector<T> vec = _base_vec;
    print_vec(vec, "before erase");
    vec.erase(vec.begin() + 1);
    print_vec(vec, "after erase");

    vec.erase(vec.begin(), vec.end());
    print_vec(vec, "after erase all");

    // emptyのeraseはセグフォ(stlと同様)
    // vec.erase(vec.begin());
    // print_vec(vec, "erase empty");
  }

  void test_swap() {
    std::cout << YELLOW << "< swap >" << RESET << std::endl;
    ft::vector<T> vec1(4, _base_vec.front());
    ft::vector<T> vec2(5, _base_vec.back());
    print_vec(vec1, "vec1");
    print_vec(vec2, "vec2");
    vec1.swap(vec2);
    print_vec(vec1, "after swap vec1");
    print_vec(vec2, "after swap vec2");
    swap(vec1, vec2);
    print_vec(vec1, "vec1 should be original");
    print_vec(vec2, "vec2 should be original");
  }

  void test_get_allocator() {
    std::cout << YELLOW << "< get_allocator >" << RESET << std::endl;
    std::cout << _base_vec.get_allocator().max_size() << std::endl << std::endl;
  }

  void test_small_funcs() {
    std::cout << YELLOW << "< small funcs >" << RESET << std::endl;
    std::cout << _base_vec.front() << std::endl;
    std::cout << _base_vec.back() << std::endl;
    std::cout << *(_base_vec.data()) << std::endl;

    std::cout << _base_vec.max_size() << std::endl;
  }

  //nafuka11さんからテスト引用
  void test_relational_operator() {
    std::cout << YELLOW << "< relational operator >" << RESET << std::endl;
    ft::vector<T> empty1;
    ft::vector<T> empty2;
    ft::vector<T> five1(5, _base_vec.front());
    ft::vector<T> five2(5, _base_vec.front());
    ft::vector<T> front_diff(5, _base_vec.front());
    ft::vector<T> back_diff(5, _base_vec.front());
    ft::vector<T> six(6, _base_vec.front());
    front_diff[0] = _base_vec.back();
    back_diff[back_diff.size() - 1] = _base_vec.back();

    std::cout << std::boolalpha << "empty == empty     : " << (empty1 == empty2)
              << std::endl
              << "empty == five      : " << (empty1 == five1) << std::endl
              << "five  == five      : " << (five1 == five2) << std::endl
              << "five  == frontDiff : " << (five1 == front_diff) << std::endl
              << "five  == backDiff  : " << (five2 == back_diff) << std::endl;
    std::cout << std::boolalpha << "empty != empty     : " << (empty1 != empty2)
              << std::endl
              << "empty != five      : " << (empty1 != five1) << std::endl
              << "five  != five      : " << (five1 != five2) << std::endl
              << "five  != frontDiff : " << (five1 != front_diff) << std::endl
              << "five  != backDiff  : " << (five2 != back_diff) << std::endl;
    std::cout << std::boolalpha
              << "empty    <  empty     : " << (empty1 < empty2) << std::endl
              << "empty    <  five      : " << (empty1 < five1) << std::endl
              << "five     <  empty     : " << (five1 < empty1) << std::endl
              << "five     <  five      : " << (five1 < five2) << std::endl
              << "six      <  five      : " << (six < five1) << std::endl
              << "five     <  six       : " << (five1 < six) << std::endl
              << "five     <  frontDiff : " << (five1 < front_diff) << std::endl
              << "frontDiff<  five      : " << (front_diff < five1) << std::endl
              << "five     <  backDiff  : " << (five2 < back_diff) << std::endl
              << "backDiff <  five      : " << (back_diff < back_diff)
              << std::endl;
    std::cout << std::boolalpha
              << "empty    <= empty     : " << (empty1 <= empty2) << std::endl
              << "empty    <= five      : " << (empty1 <= five1) << std::endl
              << "five     <= empty     : " << (five1 <= empty1) << std::endl
              << "five     <= five      : " << (five1 <= five2) << std::endl
              << "six      <= five      : " << (six <= five1) << std::endl
              << "five     <= six       : " << (five1 <= six) << std::endl
              << "five     <= frontDiff : " << (five1 <= front_diff)
              << std::endl
              << "frontDiff<= five      : " << (front_diff <= five1)
              << std::endl
              << "five     <= backDiff  : " << (five2 <= back_diff) << std::endl
              << "backDiff <= five      : " << (back_diff <= back_diff)
              << std::endl;
    std::cout << std::boolalpha
              << "empty    >  empty     : " << (empty1 > empty2) << std::endl
              << "empty    >  five      : " << (empty1 > five1) << std::endl
              << "five     >  empty     : " << (five1 > empty1) << std::endl
              << "five     >  five      : " << (five1 > five2) << std::endl
              << "six      >  five      : " << (six > five1) << std::endl
              << "five     >  six       : " << (five1 > six) << std::endl
              << "five     >  frontDiff : " << (five1 > front_diff) << std::endl
              << "frontDiff>  five      : " << (front_diff > five1) << std::endl
              << "five     >  backDiff  : " << (five2 > back_diff) << std::endl
              << "backDiff >  five      : " << (back_diff > back_diff)
              << std::endl;
    std::cout << std::boolalpha
              << "empty    >= empty     : " << (empty1 >= empty2) << std::endl
              << "empty    >= five      : " << (empty1 >= five1) << std::endl
              << "five     >= empty     : " << (five1 >= empty1) << std::endl
              << "five     >= five      : " << (five1 >= five2) << std::endl
              << "six      >= five      : " << (six >= five1) << std::endl
              << "five     >= six       : " << (five1 >= six) << std::endl
              << "five     >= frontDiff : " << (five1 >= front_diff)
              << std::endl
              << "frontDiff>= five      : " << (front_diff >= five1)
              << std::endl
              << "five     >= backDiff  : " << (five2 >= back_diff) << std::endl
              << "backDiff >= five      : " << (back_diff >= back_diff)
              << std::endl;
  }
};

#endif
