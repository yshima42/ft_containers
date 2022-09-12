#include "test_vector.hpp"
#include "test.hpp"
#include "VectorTester.hpp"
#include "VectorBenchmark.hpp"

void test_vector() {
  ft::vector<int> base(5, 10);
  VectorTester<int> v(base);
  v.test_all();
}

void benchmark_vector() {
  ft::vector<int> base(5, 10);
  VectorBenchmark<int> v(base);
  v.test_all();
}
