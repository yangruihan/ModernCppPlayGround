#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo {
public:
    std::vector<int> vec;

    MagicFoo(std::initializer_list<int> list) {
        // 从 C++11 起, 使用 auto 关键字进行类型推导
        for (auto it = list.begin(); it != list.end(); ++it) {
            vec.push_back(*it);
        }
    }
};

// c++ 20 开始支持
auto add(auto x, auto y) {
    return x + y;
}

int main() {
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    auto i = 5; // i type => int
    auto arr = new auto(10); // arr type => int*

    auto x = 5;
    auto y = 6;

    std::cout << add(x, y) << std::endl;

    std::string x2 = "123";
    std::string y2 = "234";
    std::cout << add(x2, y2) << std::endl;

    return 0;
}