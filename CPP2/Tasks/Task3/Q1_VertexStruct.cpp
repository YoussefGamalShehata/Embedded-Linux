#include <iostream>
#include <cstdlib>
struct Vertex
{
    int x = 500;
    int y = 500;

    void Generate()
    {

        // setting x with value between -100 -> 100
        while (!(x <= 100 && x >= -100))
        {
            x = std::rand();
        }
        // setting y with value between -100 -> 100
        while (!(y <= 100 && y >= -100))
        {
            y = std::rand();
        }
    }
    void Print()
    {
        std::cout << "X coordinate = " << x << std::endl;
        std::cout << "Y coordinate = " << y << std::endl;
    }
};
int main()
{
    // generate 5 Vertex
    Vertex V[5];
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Vertex Number " << i << " : " << std::endl;
        V[i].Generate();
        V[i].Print();
    }
}