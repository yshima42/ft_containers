#include <iostream>
#include <vector>

void print_vec_info(std::vector<int> &vec) {
  std::cout << std::endl
            << "size->" << vec.size() << " "
            << "capacity->" << vec.capacity() << std::endl;
}

void print_vec_elems(std::vector<int> &vec) {
  std::cout << "elems->";
  for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    std::cout << *iter << " ";
  std::cout << std::endl;
}

void print_vec(std::vector<int> &vec, const std::string &vec_name) {
  std::cout << vec_name << ": ";
  print_vec_info(vec);
  print_vec_elems(vec);
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec;
  vec.reserve(10);
  print_vec(vec, "reserve(10)");

  vec.resize(15);
  print_vec(vec, "resize(15)");
}
