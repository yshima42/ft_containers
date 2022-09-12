#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>
#include <iostream>

class Timer {
 public:
  void start();
  void stop();
  double elapsed_time() const;
  void print(const std::string &case_name) const;

 private:
  clock_t start_time_;
  clock_t stop_time_;
};

std::ostream &operator<<(std::ostream &os, const Timer &timer);

#endif
