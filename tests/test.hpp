#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#ifndef IS_FT
#define IS_FT 0
#endif

#if IS_FT
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "vector.hpp"
// CREATE A REAL STL EXAMPLE
#else
#include <map>
#include <set>
#include <stack>
#include <vector>
namespace ft = std;
#endif

#include "Timer.hpp"

#endif
