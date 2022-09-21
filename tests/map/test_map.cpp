#include "test_map.hpp"

#include "MapBenchmark.hpp"
#include "MapTester.hpp"
#include "test.hpp"

void test_map() {
  ft::map<int> base;
  for (int i = 0; i < 10; i++) {
    base.push(i);
  }
  MapTester<int> v(base);
  v.test_all();

  ft::map<std::string> base_str;
  base_str.push("str1");
  base_str.push("str2");
  base_str.push("str3");
  base_str.push("str4");
  base_str.push("str5");
  MapTester<std::string> v_str(base_str);
  v_str.test_all();
}

void benchmark_map() {
  ft::map<int> base;
  for (int i = 0; i < 10; i++) {
    base.push(i);
  }
  MapBenchmark<int> s(base);
  s.test_all();
}
