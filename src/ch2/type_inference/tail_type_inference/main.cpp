#include <iostream>

// 传统 add 写法
template<typename R, typename T, typename U>
R add(T x, U y) {
    return x + y;
}

// c++ 11 写法
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x + y) {
    return x + y;
}

// c++ 14 写法
template<typename T, typename U>
auto add3(T x, U y) {
    return x + y;
}

// ------- decltype(auto) ---------
std::string lookup1() {
    return "123";
}

const std::string &lookup2() {
    // 演示用
    return std::string("123");
}

decltype(auto) look_up_a_string_1() {
    return lookup1();
}

decltype(auto) look_up_a_string_2() {
    return lookup2();
}
// -------------------------------

int main() {
    // after c++11
    auto w = add2(1, 2.0);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    // after c++14
    auto q = add3<double, int>(1.0, 2);
    std::cout << "q: " << q << std::endl;
}