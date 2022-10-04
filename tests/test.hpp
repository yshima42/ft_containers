#ifndef TEST_HPP
#define TEST_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef IS_FT
#define IS_FT 0
#endif

#if IS_FT
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
#include "../containers/vector.hpp"
#else
namespace ft = std;
#endif

#include <list>
#include <map>
#include <stack>
#include <vector>

#include "utils/Fixed.hpp"
#include "utils/Timer.hpp"
#include "utils/color.hpp"
#include "utils/utils.hpp"

#endif
