#include "test_stack.hpp"

#include "StackBenchmark.hpp"
#include "StackTester.hpp"
#include "test.hpp"

void test_stack() {
  ft::stack<int> base;
  for (int i = 0; i < 10; i++) {
    base.push(i);
  }
  StackTester<int> v(base);
  v.test_all();

  ft::stack<std::string> base_str;
  base_str.push("str1");
  base_str.push("str2");
  base_str.push("str3");
  base_str.push("str4");
  base_str.push("str5");
  StackTester<std::string> v_str(base_str);
  v_str.test_all();
}

void benchmark_stack() {
  ft::stack<int> base;
  for (int i = 0; i < 10; i++) {
    base.push(i);
  }
  StackBenchmark<int> s(base);
  s.test_all();
}
