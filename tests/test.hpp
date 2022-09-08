#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#ifndef IS_FT
#define IS_FT 0
#endif

#if IS_FT
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#else
#include <map>
#include <stack>
#include <vector>
namespace ft = std;
#endif

#include "utils/Timer.hpp"
#include "utils/color.hpp"
#include "utils/utils.hpp"

#endif
