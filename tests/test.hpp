#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#ifndef IS_FT
#define IS_FT 0
#endif

#if IS_FT
#include "vector.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
// CREATE A REAL STL EXAMPLE
#else
#include <vector>
#include <map>
#include <stack>
#include <set>
namespace ft = std;
#endif

#include "Timer.hpp"

#endif 
