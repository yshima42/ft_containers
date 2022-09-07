#include "benchmark_stack.hpp"

benchmark_stack::benchmark_stack()
{
}

benchmark_stack::~benchmark_stack()
{
}

benchmark_stack::benchmark_stack(benchmark_stack const &other)
{
    *this = other;
}

benchmark_stack &benchmark_stack::operator=(benchmark_stack const &other)
{
    if (this != &other)
    {
    }
    return *this;
}
