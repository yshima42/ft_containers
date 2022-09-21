#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;

  // constructor
  pair() : first(), second() {}

  pair(const T1& x, const T2& y) : first(x), second(y) {}

  template <class U1, class U2>
  pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

  pair &operator = (const pair& other) {
    if (this == &other) return *this;
    first = other.first;
    second = other.second;
    return *this;
  }
};

// non-member funcs
template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return (pair<T1, T2>(x, y));
}

template <class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (!(lhs == rhs));
}

template <class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  //ここの2番目イコールにしない理由は？
  return (lhs.first < rhs.first ||
          (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (!(rhs < lhs));
}

template <class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
  return (!(lhs < rhs));
}
}  // namespace ft

#endif
