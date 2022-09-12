#include "Timer.hpp"

#include <iomanip>

void Timer::start() { start_time_ = clock(); }

void Timer::stop() { stop_time_ = clock(); }

double Timer::elapsed_time() const {
  double e_time = (double)(stop_time_ - start_time_) / CLOCKS_PER_SEC * 1000;
  return e_time;
}

void Timer::print(const std::string &case_name) const {
  std::cout << std::setw(20) << std::left << case_name;
	std::cout << this->elapsed_time() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Timer &timer) {
  os << std::fixed << std::setprecision(3) << timer.elapsed_time() << " ms";
  return os;
}
