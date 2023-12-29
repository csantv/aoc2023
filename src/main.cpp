#include <iostream>
#include <concepts>

template<class T>
concept Integral = std::is_integral<T>::value;

template<Integral T>
auto is_even(const T num) -> bool
{
    return (num & 1) == 0;
}

template<Integral T>
auto is_odd(const T num) -> bool
{
    return !is_even(num);
}

auto main(int argc, char *argv[]) -> int
{
    if (argc < 2) {
        return 0;
    }
    const auto num = std::stoull(argv[1]);
    std::cout << "Hello, World!\n";
    std::cout << "Is " << num << " even? " << std::boolalpha << is_even(num) << "\n";
    std::cout << "Is " << num << " odd? " << std::boolalpha << is_odd(num) << "\n";
    return 0;
}
