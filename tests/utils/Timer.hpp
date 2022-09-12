#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>
#include <iostream>

class Timer {
 public:
  void start(const std::string &case_name);
  void stop();
  double passed_time() const;
  void print() const;

  void stop_print();

 private:
  std::string case_name_;
  clock_t start_time_;
  clock_t stop_time_;
};

std::ostream &operator<<(std::ostream &os, const Timer &timer);

#endif
