#include "test_stack.hpp"

#include "../test.hpp"
#include "StackBenchmark.hpp"
#include "StackTester.hpp"

void test_stack() {
  ft::stack<int, ft::vector<int> > base;
  for (int i = 0; i < 10; i++) {
    base.push(i);
  }
  StackTester<int> v(base);
  std::cout << GREEN << "ft::stack<int, ft::vector<int> >" << std::endl;
  v.test_all();

  ft::stack<std::string, ft::vector<std::string> > base_str;
  base_str.push("str1");
  base_str.push("str2");
  base_str.push("str3");
  base_str.push("str4");
  base_str.push("str5");
  StackTester<std::string> v_str(base_str);
  std::cout << GREEN << "ft::stack<std::string, ft::vector<std::string> >"
            << std::endl;
  v_str.test_all();

  ft::stack<Fixed, ft::vector<Fixed> > base_fixed;
  for (Fixed i = 1.1F; i < 2; i++) {
    base_fixed.push(i);
  }
  StackTester<Fixed> v_fixed(base_fixed);
  std::cout << GREEN << "ft::stack<Fixed, ft::vector<Fixed> >" << std::endl;
  v_fixed.test_all();

  ft::stack<int, std::vector<int> > base_vector;
  for (int i = 0; i < 10; i++) {
    base_vector.push(i);
  }
  StackTester<int, std::vector<int> > v_vector(base_vector);
  std::cout << GREEN << "ft::stack<int, std::vector<int> >" << std::endl;
  v_vector.test_all();

  ft::stack<int, std::deque<int> > base_deque;
  for (int i = 0; i < 10; i++) {
    base_deque.push(i);
  }
  StackTester<int, std::deque<int> > v_deque(base_deque);
  std::cout << GREEN << "ft::stack<int, std::deque<int> >" << std::endl;
  v_deque.test_all();

  ft::stack<int, std::list<int> > base_list;
  for (int i = 0; i < 10; i++) {
    base_list.push(i);
  }
  StackTester<int, std::list<int> > v_list(base_list);
  std::cout << GREEN << "ft::stack<int, std::list<int> >" << std::endl;
  v_list.test_all();
}

void benchmark_stack() {
  ft::stack<int> base;
  for (int i = 0; i < 10; i++) {
    base.push(i);
  }
  StackBenchmark<int> s(base);
  s.test_all();
}
