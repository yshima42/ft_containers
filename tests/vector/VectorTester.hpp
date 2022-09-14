#ifndef VECTORTESTER_HPP
#define VECTORTESTER_HPP

#include <iostream>
#include <string>

// constのテストも作る
template <class T>
class VectorTester {
 public:
  VectorTester(ft::vector<T> &vec) : _base_vec(vec) {}
  ~VectorTester() {}
  void test_all() {
    test_constructor();
    test_assignment_operator();
    test_assign();
    test_push_back_pop_back();
    test_reserve_resize();
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
    // size()テスト
    std::cout << std::endl << "size->" << vec.size() << " " <<
    // capacity()テスト
    "capacity->" << vec.capacity() << std::endl;
  }

  void print_vec_elems(ft::vector<T> &vec) {
    std::cout << "elems->";
    // empty()テスト
    if (vec.empty())
      std::cout << "empty";
    // iteratorテスト
    for (typename ft::vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
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

    ft::vector<T> v3(2, 3);
    print_vec(v3, "v3(2, 3)");

    ft::vector<T> v4(2, 'x');
    print_vec(v4, "v4(2, 'x')");

    ft::vector<T> v5(_base_vec);
    print_vec(v5, "v5(_base_vec)");

    v5.clear();
    print_vec(v5, "v5.clear");

    // need to add enable_if to move this test
    ft::vector<T> v6(v4.begin(), v4.end());
    print_vec(v6, "v6(v4.begin(), v4.end())");
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

  void test_assign() {
   ft::vector<T> characters;
   characters.assign(5, 'a');
   print_vec(characters, "characters.assign(5, 'a')");

  //  ft::vector<T> it_assign;
  //  it_assign.assign(characters.begin(), characters.end());
  //  print_vec(it_assign, "it_assign.assign(characters.begin(), characters.end())");

  }
  
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

  void test_reserve_resize() {
    ft::vector<T> vec;
    vec.reserve(10);
    print_vec(vec, "reserve(10)");

    vec.resize(15, 0);
    print_vec(vec, "resize(15)");

    _base_vec.resize(6, 1);
    print_vec(_base_vec, "_base_vec.resize(5)");
  }

};

#endif
