#include "vector/test_vector.hpp"
#include "map/benchmark_map.hpp"
#include "map/test_map.hpp"
#include "stack/test_stack.hpp"
#include "test.hpp"

const std::string containers[] = {"vector", "map", "stack"};

void (*const test_funcs[])(void) = {test_vector, test_map, test_stack};

void (*const benchmark_funcs[])(void) = {benchmark_vector, benchmark_map, benchmark_stack};

int container_index(std::string arg) {
  int i = 0;
  while (i < 3) {
    if (arg == containers[i]) {
		return i;
	}
    i++;
  }
  return (-1);
}

int main(int ac, char *av[]) {
  if (ac != 3) std::cout << "need 3 args" << std::endl;

  std::string arg_str = av[1];
  int index = container_index(av[2]);

  if (arg_str == "-t") {
    test_funcs[index]();
  } else if (arg_str == "-b") {
    benchmark_funcs[index]();
  }
}
