#include <iomanip>
#include "Timer.hpp"

void Timer::start()
{
    start_time_ = clock();
}

void Timer::stop()
{
    stop_time_ = clock();
}

double Timer::print() const
{
    double time = (double)(stop_time_ - start_time_) / CLOCKS_PER_SEC * 1000;
    return time;
}

std::ostream &operator<<(std::ostream &os, const Timer &timer)
{
    os << std::fixed << std::setprecision(3) << timer.print() << " ms";
    return os;
}

