#include <iostream>

using namespace std;

template <class T>
void intCheck(T x, typename enable_if<std::is_integral<T>::value>::type* = 0) {
  cout << "xは整数" << endl;
}

int main() { intCheck(10); }
