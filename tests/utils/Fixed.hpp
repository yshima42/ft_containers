#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int _raw;
  static const int _point = 8;

 public:
  Fixed();
  Fixed(int n);
  Fixed(float n);
  ~Fixed();
  Fixed(Fixed const &other);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  Fixed &operator=(Fixed const &other);

  bool operator==(Fixed const &other) const;
  bool operator!=(Fixed const &other) const;
  bool operator>(Fixed const &other) const;
  bool operator>=(Fixed const &other) const;
  bool operator<(Fixed const &other) const;
  bool operator<=(Fixed const &other) const;

  Fixed operator+(Fixed const &other) const;
  Fixed operator-(Fixed const &other) const;
  Fixed operator*(Fixed const &other) const;
  Fixed operator/(Fixed const &other) const;

  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  static Fixed &min(Fixed &f1, Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &ost, Fixed const &fixed);

#endif
