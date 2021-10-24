#include <iostream>
#include <vector>

// ----- 外部模板 -----

template
class std::vector<bool>;          // 强行实例化

extern template
class std::vector<double>;        // 不在该当前编译文件中实例化模板

// ----------

// ----- 尖括号支持 ------
template<bool T>
class MagicType {
    bool magic = T;
};

template
class std::vector<MagicType<(1 > 2)>>; // 合法, 但不建议写出这样的代码

// ----------

// ----- 类型别名模板 -----
template<typename T, typename U>
class OtherMagicType {
public:
    T dark;
    U magic;
};

typedef int (*process)(void *);

using NewProcess = int (*)(void *);

template<typename T>
using TrueDrakMagic = OtherMagicType<std::vector<T>, std::string>;

// ----------

// ----- 变长参数模板 -----

template<typename ... Ts>
class Magic {
};

template
class Magic<int,
        std::vector<int>,
        double,
        std::string>;

template
class Magic<>; // nothing

template<typename ... Ts>
void magic(Ts ... args) {
    std::cout << sizeof...(args) << std::endl;
}

// 参数解包
// 1 递归模板函数
template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...);
}

// 2 变参模板展开
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0) printf2(t...);
}

// 初始化列表展开
template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void) std::initializer_list<T>{([&args] {
        std::cout << args << std::endl;
    }(), value)...};
}

// ----------

// ----- 折叠表达式 -----

template<typename ... T>
auto sum(T ... t) {
    return (t + ...);
}

// ----------

// ----- 非类型模板参数推导 -----

template<typename T, int BufSize>
class buffer_t {
public:
    T &alloc();

    void free(T &item);

private:
    T data[BufSize];
};

buffer_t<int, 100> buf;

template<auto value>
void foo() {
    std::cout << value << std::endl;
}

// ----------

int main() {
    std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;

    foo<10>();
}