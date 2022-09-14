#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

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
  typedef ft::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef ft::random_access_iterator_tag iterator_category;
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

template <class Iter>
class reverse_iterator
    : public iterator<typename ft::iterator_traits<Iter>::iterator_category,
                      typename ft::iterator_traits<Iter>::value_type,
                      typename ft::iterator_traits<Iter>::difference_type,
                      typename ft::iterator_traits<Iter>::pointer,
                      typename ft::iterator_traits<Iter>::reference> {
 protected:
  Iter _current;
  typedef ft::iterator_traits<Iter> traits_type;

 public:
  typedef Iter iterator_type;
  typedef typename traits_type::iterator_category iterator_category;
  typedef typename traits_type::value_type value_type;
  typedef typename traits_type::difference_type difference_type;
  typedef typename traits_type::pointer pointer;
  typedef typename traits_type::reference reference;

  // constructor
  reverse_iterator() : _current() {}
  explicit reverse_iterator(iterator_type x) : _current(x) {}
  template <class U>
  reverse_iterator(const reverse_iterator<U>& other) : _current(other.base()) {}

  // operator=
  template <class U>
  reverse_iterator& operator=(const ft::reverse_iterator<U>& other) {
    _current = other.base();
    return *this;
  }

  // destructor
  virtual ~reverse_iterator() {}

  // funcs
  iterator_type base() const { return _current; }

  // operator *
  // reverseでendの部分が一つずれているので
  reference operator*() const {
    Iter tmp = _current;
    return *--tmp;
  }

  // operator ->
  pointer operator->() const { return &(operator*()); }

  // operator []
  reference operator[](difference_type n) const { return *(*this + n); }

  // other operators
  reverse_iterator& operator++() {
    --_current;
    return *this;
  }
  reverse_iterator& operator--() {
    ++_current;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator tmp = *this;
    --_current;
    return tmp;
  }
  reverse_iterator operator--(int) {
    reverse_iterator tmp = *this;
    ++_current;
    return tmp;
  }
  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(_current - n);
  }
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(_current + n);
  }
  reverse_iterator& operator+=(difference_type n) {
    _current -= n;
    return *this;
  }
  reverse_iterator& operator-=(difference_type n) {
    _current += n;
    return *this;
  }
};

// nomember_functions
template <class Iterator1, class Iterator2>
bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs.base() == rhs.base();
}
template <class Iterator1, class Iterator2>
bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return !(lhs == rhs);
}

template <class Iterator1, class Iterator2>
bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
               const ft::reverse_iterator<Iterator2>& rhs) {
  return rhs.base() < lhs.base();
}
template <class Iterator1, class Iterator2>
bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
               const ft::reverse_iterator<Iterator2>& rhs) {
  return lhs < rhs;
}
template <class Iterator1, class Iterator2>
bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return !(rhs < lhs);
}
template <class Iterator1, class Iterator2>
bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs) {
  return !(lhs < rhs);
}

template <class Iter>
ft::reverse_iterator<Iter> operator+(
    typename ft::reverse_iterator<Iter>::difference_type n,
    const ft::reverse_iterator<Iter>& it) {
  return ft::reverse_iterator<Iter>(it.base() - n);
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator-(
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
  return rhs.base() - lhs.base();
}

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
