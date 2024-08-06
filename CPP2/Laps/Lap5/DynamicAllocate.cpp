#include <iostream>
#include <string>

namespace DynamicAlloc {
    void create2DArray(int **&arr, int size) 
    {
        arr = new int*[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = new int[size];  
        }
    }

    void delete2DArray(int **arr, int size) 
    {
        for (int i = 0; i < size; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr;
    }
}

int main()
{
    int size = 2;
    int **arr = nullptr;

    DynamicAlloc::create2DArray(arr, size);

    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            arr[i][j] = j + i + 5;
        }
    }

    std::cout << "2D Array:" << std::endl;
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    DynamicAlloc::delete2DArray(arr, size);
}