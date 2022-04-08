#include "test.hpp"
#include "benchmark_vector.hpp"


void bm_constractor()
{
  Timer time;
  time.start();
  ft::vector<int> a(2, 3);
  time.stop();
  std::cout << time;

}

void benchmark_vector()
{
  bm_constractor();
}
