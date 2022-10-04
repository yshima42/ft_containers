#include "test_vector.hpp"

#include "../test.hpp"
#include "VectorBenchmark.hpp"
#include "VectorTester.hpp"

void test_vector() {
  ft::vector<int> base;
  for (int i = 0; i < 10; i++) {
    base.push_back(i);
  }
  VectorTester<int> v(base);
  v.test_all();

  ft::vector<std::string> base_str;
  base_str.push_back("str1");
  base_str.push_back("str2");
  base_str.push_back("str3");
  base_str.push_back("str4");
  base_str.push_back("str5");
  VectorTester<std::string> v_str(base_str);
  v_str.test_all();

  ft::vector<Fixed> base_fixed(5, 2.5f);
  VectorTester<Fixed> v_fixed(base_fixed);
  v_fixed.test_all();
}

void benchmark_vector() {
  ft::vector<int> base(10000, 10);
  VectorBenchmark<int> v(base);
  v.test_all();
}
