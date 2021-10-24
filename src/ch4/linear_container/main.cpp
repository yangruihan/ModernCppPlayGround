#include <array>
#include <algorithm>

void foo(int *p, int len) {
    return;
}

int main() {
    // 定长数组 std::array
    std::array<int, 4> arr = {1, 2, 3, 4};

    arr.empty(); // 检查容器是否为空
    arr.size();  // 返回容纳的元素数

    // 迭代器支持
    for (auto &i: arr) {
        // ...
    }

    // 用 lambda 表达式排序
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return b < a;
    });

    // 数组大小参数必须是常量表达式
    constexpr int len = 4;
    std::array<int, len> arr2 = {1, 2, 3, 4};

    // 非法,不同于 C 风格数组，std::array 不会自动退化成 T*
    // int *arr_p = arr;

    // 兼容 C API
    foo(&arr2[0], arr.size());
    foo(arr2.data(), arr.size());
}