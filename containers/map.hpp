#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iostream>
#include "../utils/pair.hpp"

namespace ft {
    template <class Key, class T> //, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> >
    class map {
        public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        //typedef Compare key_compare;

        map() {}
        
    };
}

#endif
