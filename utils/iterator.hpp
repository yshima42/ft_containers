#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>

namespace ft {

template <class Iterator>
struct iterator_traits {
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
};

template <class T>
struct iterator_traits<T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <class Category, class T, class Distance = std::ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
  typedef Category iterator_category;
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
};

// functions
template <class InputIterator, class Distance>
void advance(InputIterator& it, Distance n) {
  while (n > 0) {
    ++it;
    --n;
  }
  while (n < 0) {
    --it;
    ++n;
  }
  return;
}

template <class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type distance(
    InputIterator first, InputIterator last) {
  typename ft::iterator_traits<InputIterator>::difference_type ret = 0;
  while (first != last) {
    ++first;
    ++ret;
  }
  return (ret);
}

}  // namespace ft

#endif
