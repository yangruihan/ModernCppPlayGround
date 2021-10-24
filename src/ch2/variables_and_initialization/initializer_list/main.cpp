#include <iostream>
#include <vector>

class Foo {
public:
    int value_a;
    int value_b;

    Foo(int a, int b) : value_a(a), value_b(b) {}
};

// c++ 11 之后
#include <initializer_list>

class MagicFoo {
public:
    std::vector<int> vec;

    // initializer_list 用在构造函数
    MagicFoo(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            vec.push_back(*it);
        }
    }

    // 用在普通函数
    void foo(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            vec.push_back(*it);
        }
    }
};

int main() {
    // c++ 11 之前
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // c++ 11 之后
    MagicFoo magicFoo = {1, 2, 3, 4, 5};

    std::cout << "magicFoo: " << std::endl;
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
        std::cout << *it << std::endl;

    magicFoo.foo({6, 7, 8, 9, 0});

    std::cout << "magicFoo: " << std::endl;
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
        std::cout << *it << std::endl;

    Foo foo1{3, 4};

    MagicFoo foo2{4, 5, 6};

    return 0;
}