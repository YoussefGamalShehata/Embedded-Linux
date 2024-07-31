#include <iostream>
#include <atomic>
#include <thread>

class SpinLock {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    void lock() {
        while (flag.test_and_set(std::memory_order_acquire)) {
        }
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

SpinLock spinlock;
int shared_variable = 1;

void multiply() {
    for (int i = 0; i < 100; ++i) {
        spinlock.lock();
        shared_variable *= 2;
        spinlock.unlock();
    }
}

void divide() {
    for (int i = 0; i < 100; ++i) {
        spinlock.lock();
        shared_variable /= 2;
        spinlock.unlock();
    }
}

int main() {
    std::thread t1(multiply);
    std::thread t2(divide);

    t1.join();
    t2.join();

    std::cout << "Final value of shared variable: " << shared_variable << std::endl;

    return 0;
}
