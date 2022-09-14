#include <iostream>
#include <type_traits>

template<
    typename T,
    typename std::enable_if<std::is_integral<T>::value, std::nullptr_t>::type = nullptr
>
void
func(T t){
    std::cout << t << "は整数だよ" << std::endl;
}

int main() {
    func(3);
}