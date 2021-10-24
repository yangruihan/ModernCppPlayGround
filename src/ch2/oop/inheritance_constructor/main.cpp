#include <iostream>

class Base {
public:
    int value1;
    int value2;

    Base() {
        value1 = 1;
    }

    Base(int value) : Base() {
        value2 = value;
    }
};

class SubClass : public Base {
public:
    using Base::Base; // 继承构造
};

int main() {
    SubClass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;
}