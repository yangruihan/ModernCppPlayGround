#include <iostream>
#include <string>

void reference(std::string &str) {
    std::cout << "lvalue" << std::endl;
}

void reference(std::string &&str) {
    std::cout << "rvalue" << std::endl;
}

void reference(int &v) {
    std::cout << "左值引用" << std::endl;
}

void reference(int &&v) {
    std::cout << "右值引用" << std::endl;
}

// 移动语义
class A {
public:
    int *pointer;

    A() : pointer(new int(1)) {
        std::cout << "构造 " << pointer << std::endl;
    }

    A(A &a) : pointer(new int(*a.pointer)) {
        std::cout << "拷贝 " << pointer << std::endl;
    } // 无意义的对象拷贝

    A(A &&a) : pointer(a.pointer) {
        a.pointer = nullptr;
        std::cout << "移动 " << pointer << std::endl;
    }

    ~A() {
        std::cout << "析构 " << pointer << std::endl;
        delete pointer;
    }
};

// 防止编译器优化
A return_rvalue(bool test) {
    A a, b;
    if (test) return a; // 等价于 static_cast<A&&>(a);
    else return b;     // 等价于 static_cast<A&&>(b);
}


// 完美转发
template<typename T>
void pass(T &&v) {
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T &&>(v));
}

int main() {
    std::string lv1 = "string,"; // lv1 是一个左值
    // std::string&& r1 = lv1; // 非法, 右值引用不能引用左值
    std::string &&rv1 = std::move(lv1); // 合法, std::move可以将左值转移为右值
    std::cout << rv1 << std::endl; // string,

    const std::string &lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    std::cout << lv2 << std::endl; // string,string,

    std::string &&rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
    rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
    std::cout << rv2 << std::endl; // string,string,string,Test

    reference(rv2); // 输出左值


    // ----- 移动语义测试 -----
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;


    // ----- 完美转发测试 -----
    std::cout << "传递右值:" << std::endl;
    pass(1);

    std::cout << "传递左值:" << std::endl;
    int v = 1;
    pass(v);

    return 0;
}