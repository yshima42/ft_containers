#include "benchmark_map.hpp"

benchmark_map::benchmark_map()
{
}

benchmark_map::~benchmark_map()
{
}

benchmark_map::benchmark_map(benchmark_map const &other)
{
    *this = other;
}

benchmark_map &benchmark_map::operator=(benchmark_map const &other)
{
    if (this != &other)
    {
    }
    return *this;
}
