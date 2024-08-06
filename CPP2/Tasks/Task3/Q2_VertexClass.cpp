#include <iostream>
#include <cstdlib>
class Vertex
{
private:
    int x;
    int y;

public:
    Vertex() : x(500), y(500)
    {
        while (!(x <= 100 && x >= -100))
        {
            x = rand();
        }
        while (!(y <= 100 && y >= -100))
        {
            y = rand();
        }
    }
    void Set_X(int a)
    {
        this->x = a;
    }
    void Set_Y(int b)
    {
        this->y = b;
    }
    int Get_X()
    {
        return this->x;
    }
    int Get_Y()
    {
        return this->y;
    }
    std::string Vertex_Reading()
    {
        return "Vertex(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};
int main()
{
    Vertex V1;
    std::string ret = V1.Vertex_Reading();
    std::cout << ret << std::endl;
}