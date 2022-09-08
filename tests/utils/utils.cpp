#include "utils.hpp"

void print_time(const std::string &case_name, const Timer &time) {
	std::cout << std::setw(20) << std::left << case_name;
	std::cout << time << std::endl;
}
