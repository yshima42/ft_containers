#include "benchmark_vector.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "test.hpp"

void bm_constructor(Timer time) {
  std::string case_name = "constructor";

  time.start();
  ft::vector<int> a(2, 3);
  time.stop();
  std::cout << std::setw(20) << std::left << case_name;
  std::cout << time << std::endl;
}

void benchmark_vector() {
  Timer time;
  bm_constructor(time);
}
