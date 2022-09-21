#include "test_map.hpp"

#include "MapBenchmark.hpp"
#include "MapTester.hpp"
#include "PairTester.hpp"
#include "test.hpp"

void test_pair() {
  std::cout << "(pair test)" << std::endl;
  ft::pair<int, int> p1(1, 2);
  PairTester<int, int> p(p1);
  p.test_all();
}

void test_map() {
  test_pair();
  ft::map<int, int> base;
  MapTester<int, int> v(base);
  v.test_all();

  // ft::map<std::string, std::string> base_str;
  // MapTester<std::string, std::string> v_str(base_str);
  // v_str.test_all();
}

void benchmark_map() {
  // ft::map<int, int> base;
  // MapBenchmark<int, int> s(base);
  // s.test_all();
}
