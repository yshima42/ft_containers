#include "test_vector.hpp"

#include "VectorBenchmark.hpp"
#include "VectorTester.hpp"
#include "test.hpp"

void test_vector() {
  ft::vector<int> base(5, 10);
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
}

void benchmark_vector() {
  ft::vector<int> base(5, 10);
  VectorBenchmark<int> v(base);
  v.test_all();
}
