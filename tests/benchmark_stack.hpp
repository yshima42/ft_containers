#ifndef BENCHMARK_STACK_HPP
# define BENCHMARK_STACK_HPP

class benchmark_stack
{
    public:
        benchmark_stack();
        virtual ~benchmark_stack();
        benchmark_stack(benchmark_stack const &other);
        benchmark_stack &operator=(benchmark_stack const &other);

    private:
};

#endif
