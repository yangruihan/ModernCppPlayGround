#include <iostream>

enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

template<typename T>
std::ostream &operator<<(typename std::enable_if<std::is_enum<T>::value,
        std::ostream>::type &stream, const T &e) {
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main() {
    auto e = new_enum::value1;

    if (e == new_enum::value1) {
        std::cout << "e == new_enum::value1" << std::endl;
    }

    std::cout << new_enum::value3 << std::endl;
}