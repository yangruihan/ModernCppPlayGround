#include <iostream>
#include <thread>
#include <mutex>

int v = 1;
int v2 = 1;

void critical_section(int change_v) {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);

    // 执行竞争操作
    v += change_v;

    // 离开此作用域后 mtx 会被释放
}

void critical_section2(int change_v) {
    static std::mutex mtx;

    std::unique_lock<std::mutex> lock(mtx);
    // 执行竞争操作
    v2 = change_v;
    std::cout << v2 << std::endl;
    // 将锁进行释放
    lock.unlock();

    // 在此期间，任何人都可以抢夺 v 的持有权

    // 开始另一组竞争操作，再次加锁
    lock.lock();
    v2 += 1;
    std::cout << v2 << std::endl;
}

int main() {
    std::thread t1(critical_section, 2), t2(critical_section, 3);
    t1.join();
    t2.join();

    std::cout << v << std::endl;

    std::cout << "-----" << std::endl;

    std::thread t3(critical_section2, 2), t4(critical_section2, 3);
    t3.join();
    t4.join();
    return 0;
}