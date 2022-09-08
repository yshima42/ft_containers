#include "test_vector.hpp"
#include "test.hpp"
#include "VectorTester.hpp"

void test_vector() {
  ft::vector<int> base(5, 10);
  VectorTester<int> v(base);
  v.test_all();
}
