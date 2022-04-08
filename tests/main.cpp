#include "test.hpp"
#include "test_vector.hpp"
#include "benchmark_vector.hpp"

const std::string containers[] = {
  "vector",
  "map",
  "stack"
};

void (*const test_funcs[])(void) = {
  test_vector
};

void (*const benchmark_funcs[])(void) = {
  benchmark_vector
};

int container_index(std::string arg)
{
  int i = 0;
  while (i < 1) {
    if (arg == containers[i])
      return i;
    i++;
  }
  return (-1);
}

int main(int ac, char *av[])
{
  if (ac != 3)
    std::cout << "need 3 args" << std::endl;

  std::string arg_str = av[1];
  int index = container_index(av[2]);

  if (arg_str == "-t") {
    test_funcs[index]();
  } else if (arg_str == "-b") {
    benchmark_funcs[index]();
  }
}
