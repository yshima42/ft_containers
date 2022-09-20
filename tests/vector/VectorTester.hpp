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
    test_erase();
    test_swap();
    test_get_allocator();
    test_small_funcs();
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
    print_vec(v3, "v3(2, _base_vec.at(1))");

    ft::vector<T> v5(_base_vec);
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
    print_vec(it_assign,
              "it_assign.assign(v.begin(), v.end())");

    //後ほど対応
    //  std::stringstream ss;
    // ss << 1 << std::endl << 2 << std::endl << 3;

    // std::istream_iterator< int > beg(ss);
    // std::istream_iterator< int > last;

    // ft::vector< int > v;
    // v.assign(beg, last);
    // for (ft::vector< int >::iterator it = v.begin(); it != v.end(); it++) {
    //   std::cout << *it << std::endl;
    // }
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

    _base_vec.resize(6, _base_vec.at(4));
    print_vec(_base_vec, "_base_vec.resize(5)");
  }

  void test_insert() {
    std::cout << YELLOW << "< insert >" << RESET << std::endl;
    ft::vector<T> vec(_base_vec);
    vec.insert((vec.begin() + 1), vec.at(4));
    print_vec(vec, "vec.insert((vec.begin() + 1), vec.at(4))");
  }

  void test_erase() {
    std::cout << YELLOW << "< erase >" << RESET << std::endl;
    ft::vector<T> vec = _base_vec;
    print_vec(vec, "before erase");
    vec.erase(vec.begin() + 1);
    print_vec(vec, "after erase");

    vec.erase(vec.begin(), vec.end());
    print_vec(vec, "after erase all");

    // emptyを消そうとするとstlもセグフォする
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
    // 後ほど自分で作ったallocatorテストを追加する
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
};

#endif
