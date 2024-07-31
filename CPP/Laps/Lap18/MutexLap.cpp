#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int fib_results[4] = {0, 0, 0, 0};
bool results_ready[4] = {false, false, false, false};
std::mutex mtx;
std::condition_variable cv;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void calculate_fibonacci(int n, int index)
{
    int result = fibonacci(n);

    std::unique_lock<std::mutex> lock(mtx);
    fib_results[index] = result;
    results_ready[index] = true;
    lock.unlock();

    cv.notify_all();
}

void print_results()
{
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [&]
            { return results_ready[0] && results_ready[1] && results_ready[2] && results_ready[3]; });

    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Fibonacci(" << ((i == 0) ? 4 : (i == 1) ? 9
                                                 : (i == 2)   ? 14
                                                              : 17)
                  << ") = " << fib_results[i] << std::endl;
        sum += fib_results[i];
    }
    std::cout << "Sum = " << sum << std::endl;
}
int main()
{
    int indices[] = {4, 9, 14, 17};
    std::thread threads[4];

    for (int i = 0; i < 4; ++i)
    {
        threads[i] = std::thread(calculate_fibonacci, indices[i], i);
    }

    std::thread print_thread(print_results);

    for (int i = 0; i < 4; ++i)
    {
        threads[i].join();
    }
    print_thread.join();

    return 0;
}
