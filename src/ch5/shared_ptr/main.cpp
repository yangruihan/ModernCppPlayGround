#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i) {
    (*i)++;
}

int main() {
    {
        // auto pointer = new int(10); // illegal, no direct assignment
        // Constructed a std::shared_ptr
        auto pointer = std::make_shared<int>(10);
        foo(pointer);
        std::cout << *pointer << std::endl; // 11
        // The shared_ptr will be destructed before leaving the scope
    }

    {
        auto pointer = std::make_shared<int>(10);
        auto pointer2 = pointer; // 引用计数+1
        auto pointer3 = pointer; // 引用计数+1
        int *p = pointer.get(); // 这样不会增加引用计数
        std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
        std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
        std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

        pointer2.reset();
        std::cout << "reset pointer2:" << std::endl;
        std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
        std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
        std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
        pointer3.reset();
        std::cout << "reset pointer3:" << std::endl;
        std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
        std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
        std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset
    }

    return 0;
}