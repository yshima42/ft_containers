#include "test.hpp"
#include "test_vector.hpp"

void test_constractor()
{
  ft::vector<char> a;
  std::cout << a.size() << std::endl;

  ft::vector<int> v(1);
  std::cout << v.size() << std::endl;

  ft::vector<int> v2(10);
  std::cout << v2.size() << std::endl;

}

void test_vector()
{
  test_constractor();

}
