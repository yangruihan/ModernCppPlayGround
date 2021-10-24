#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // 在 c++ 17 之前
    auto itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    // 需要重新定义一个新的变量
    auto itr2 = std::find(vec.begin(), vec.end(), 3);
    if (itr2 != vec.end()) {
        *itr2 = 4;
    }

    for (auto element = vec.begin(); element != vec.end(); ++element) {
        std::cout << *element << std::endl;
    }

    std::cout << "------" << std::endl;

    // c++ 17 之后
    if (auto itr3 = std::find(vec.begin(), vec.end(), 3);
            itr3 != vec.end()) {
        *itr3 = 4;
    }

    for (auto element = vec.begin(); element != vec.end(); ++element) {
        std::cout << *element << std::endl;
    }
}