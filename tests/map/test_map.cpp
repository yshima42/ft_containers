#include "test_map.hpp"

#include "MapBenchmark.hpp"
#include "MapTester.hpp"
#include "PairTester.hpp"
#include "test.hpp"

void test_pair() {
  std::cout << "(pair test)" << std::endl;
  ft::pair<int, std::string> p1(1, "hello");
  PairTester<int, std::string> p(p1);
  p.test_all();
}

void test_map() {
  test_pair();
  ft::pair<int, std::string> pair_elems[] = {
      ft::make_pair(-1, "A"), ft::make_pair(0, "B"), ft::make_pair(1, "C"),
      ft::make_pair(2, "D"),  ft::make_pair(3, "E"),
  };

  ft::pair<int, std::string> test_pairs[] = {
        ft::make_pair(10, "ccccc"), ft::make_pair(-10, "aaaaa"),
        ft::make_pair(30, "eeeee"), ft::make_pair(20, "ddddd"),
        ft::make_pair(0, "bbbbb"),
  };

  ft::map<int, std::string> base_map;
  for (size_t i = 0; i < 5; i++) {
    base_map.insert(pair_elems[i]);
  }

  MapTester<int, std::string> m(base_map, test_pairs);
  // std::cout << base_map.at(0);
  m.test_all();

  // ft::map<std::string, std::string> base_str;
  // MapTester<std::string, std::string> v_str(base_str);
  // v_str.test_all();
}

void benchmark_map() {
  // ft::map<int, int> base;
  // MapBenchmark<int, int> s(base);
  // s.test_all();
}
