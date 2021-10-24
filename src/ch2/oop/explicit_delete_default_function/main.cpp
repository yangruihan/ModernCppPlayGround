class Magic {
public:
    Magic() = default; // 显示声明使用编译器生成的构造
    Magic &operator=(const Magic &) = delete; // 显示声明拒绝编译器生成的构造
    Magic(int magic_number);
};

int main() {
}