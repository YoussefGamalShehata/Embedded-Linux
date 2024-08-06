#include <iostream>
#include <thread>

void Beeb(int seconds)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        std::cout << "\a" << std::endl;
    }
}
void stop()
{
    char e;
    while (true)
    {
        std::cout << "Please Press Enter to terminate" << std::endl;
        e = std::cin.get();
        if (e == '\n')
        {
            exit(0);
        }
    }
}
int main()
{
    int s = 3;
    char e;
    std::thread t1(Beeb, s);
    std::thread t2(stop);
    t1.join();
    t2.join();
    std::cout << "program terminated" << std::endl;
}