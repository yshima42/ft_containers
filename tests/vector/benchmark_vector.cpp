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
  time.print(case_name);
}


// void bm_assign(Timer time) {
//   std::string case_name = "assign";

//   ft::vector<int> vec;
//   time.start();
//   for (size_t i = 0; i < 10; i++) {
//     vec.assign(1, 2);
//   }
//   time.stop();
//   print_time(case_name, time);
// }

void benchmark_vector() {
  Timer time;
  bm_constructor(time);
}
