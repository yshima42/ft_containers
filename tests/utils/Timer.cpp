#include "Timer.hpp"

#include <iomanip>

void Timer::start(const std::string &case_name) {
   case_name_ = case_name;
   start_time_ = clock();
   }

void Timer::stop() { stop_time_ = clock(); }

double Timer::passed_time() const {
  double p_time = (double)(stop_time_ - start_time_) / CLOCKS_PER_SEC * 1000;
  return p_time;
}

void Timer::print() const {
  std::cout << std::setw(20) << std::left << case_name_;
	std::cout << this->passed_time() << std::endl;
}

void Timer::stop_print() {
  this->stop();
  this->print();
}

std::ostream &operator<<(std::ostream &os, const Timer &timer) {
  os << std::fixed << std::setprecision(3) << timer.passed_time() << " ms";
  return os;
}
