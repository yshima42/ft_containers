#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
 public:
  typedef T value_type;
  typedef Container container_type;
  typedef size_t size_type;

  explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}

  stack(const stack &other) : c(other.c) {}

  ~stack() {}

  bool empty() const { return c.empty(); }

  size_type size() const { return c.size(); }

  value_type &top() { return c.back(); }

  const value_type &top() const { return c.back(); }

  void push(const value_type &val) { c.push_back(val); }

  void pop() { return c.pop_back(); }

  // Non-member functions
  friend bool operator==(const stack<T, Container> &lhs,
                         const stack<T, Container> &rhs) {
    return lhs.c == rhs.c;
  }
  friend bool operator!=(const stack<T, Container> &lhs,
                         const stack<T, Container> &rhs) {
    return !(lhs.c == rhs.c);
  }
  friend bool operator<(const stack<T, Container> &lhs,
                        const stack<T, Container> &rhs) {
    return lhs.c < rhs.c;
  }
  friend bool operator<=(const stack<T, Container> &lhs,
                         const stack<T, Container> &rhs) {
    return !(rhs.c < lhs.c);
  }
  friend bool operator>(const stack<T, Container> &lhs,
                        const stack<T, Container> &rhs) {
    return rhs.c < lhs.c;
  }
  friend bool operator>=(const stack<T, Container> &lhs,
                         const stack<T, Container> &rhs) {
    return !(lhs.c < rhs.c);
  }

 protected:
  Container c;
};

}  // namespace ft

#endif
