#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef IS_FT
#define IS_FT 0
#endif

#if IS_FT
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
#else
namespace ft = std;
#endif

#include <map>
#include <stack>
#include <vector>
#include <list>

#include "utils/Timer.hpp"
#include "utils/color.hpp"
#include "utils/Fixed.hpp"
#include "utils/utils.hpp"

#endif
