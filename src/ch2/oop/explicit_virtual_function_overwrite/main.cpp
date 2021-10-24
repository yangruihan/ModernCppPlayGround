struct Base {
    virtual void foo(int);

    virtual void foo2(int) final;
};

struct SubClass final : Base {
    virtual void foo(int) override; // 显示覆盖

//    virtual void foo2(int) override; // 非法，虚方法声明 final
};

struct SubClass2 { // : SubClass { // 非法，SubClass 声明 final
};

int main() {
}