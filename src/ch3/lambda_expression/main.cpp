#include <iostream>

// 值捕获
void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 1, 而 value == 100.
    // 因为 copy_value 在创建时就保存了一份 value 的拷贝
}

// 引用捕获
void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 100, value == 100.
    // 因为 copy_value 保存的是引用
}

/*
 * 隐式捕获
 * [] 空捕获列表
 * [name1, name2, ...] 捕获一系列变量
 * [&] 引用捕获, 让编译器自行推导引用列表
 * [=] 值捕获, 让编译器自行推导值捕获列表
 */

// 表达式捕获
void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };

    std::cout << add(3, 4) << std::endl;
}

// 泛化 lambda
void generic_lambda() {
    auto generic = [](auto x, auto y) {
        return x + y;
    };

    std::cout << generic(1, 2) << std::endl;
    std::cout << generic(1.1, 2.2) << std::endl;
}

int main() {
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_capture();
    generic_lambda();
}