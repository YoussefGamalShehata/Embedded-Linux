#include <iostream>
template <typename T>
class My_Vector
{
private:
    int CurrentSize;
    int Capacity;
    T *Arr;

public:
    /*Special Function Methods*/
    My_Vector() : Capacity(1), CurrentSize(0)
    {
        Arr = new T[Capacity];
    }
    My_Vector(int Cap) : Capacity(Cap), CurrentSize(0) {}
    My_Vector(int Cap, T value) : Capacity(Cap), CurrentSize(Cap)
    {
        if (Cap == 0)
        {
            std::cout << "Invalid Capacity to create Vector" << std::endl;
        }
        else
        {
            Arr = new T[Capacity];
            for (int i = 0; i < CurrentSize; i++)
            {
                Arr[i] = value;
            }
        }
    }
    My_Vector(int Cap, T *value) : Capacity(Cap), CurrentSize(Cap)
    {
        Arr = new T[Capacity];
        for (int i = 0; i < CurrentSize; i++)
        {
            Arr[i] = value[i];
        }
    }
    My_Vector(const My_Vector &Obj)
    {
        this->Capacity = Obj.Capacity;
        this->CurrentSize = Obj.CurrentSize;
        this->Arr = new T[Capacity];
        for (int i = 0; i < this->Capacity; i++)
        {
            this->Arr[i] = Obj.Arr[i];
        }
    }
    /*Normal Function Methods*/
    int Vector_size(void)
    {
        return this->CurrentSize;
    }
    int Vector_Capacity(void)
    {
        return this->Capacity;
    }
    void Vector_print(void)
    {
        std::cout << "Your Vector Elements : \n";
        for (int i = 0; i < this->CurrentSize; i++)
        {
            std::cout << this->Arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void Vector_resize(void)
    {
        this->Capacity *= 2;
        T *newArr = new T[this->Capacity];
        for (int i = 0; i < (this->CurrentSize); i++)
        {
            newArr[i] = this->Arr[i];
        }
        delete[] Arr;
        Arr = newArr;
        std::cout << "New Capacity = " << this->Capacity << std::endl;
    }
    void Vector_pushback(T value)
    {
        if (this->Capacity == this->CurrentSize)
        {
            Vector_resize();
            this->Arr[CurrentSize - 1] = value;
        }
        else
        {
            if (CurrentSize != 0)
            {
                this->Arr[0] = value;
            }
            else
            {
                this->Arr[CurrentSize - 1] = value;
            }
            CurrentSize++;
        }
    }
    void Vector_popback(void)
    {
        if (this->CurrentSize == 0)
        {
            std::cout << "No Elements to be deleted" << std::endl;
        }
        else
        {
            this->CurrentSize--;
        }
    }
    void Vector_removeAt(int index)
    {
        for (int i = index; i < (this->CurrentSize - 1); i++)
        {
            this->Arr[i] = this->Arr[i + 1];
        }
        this->CurrentSize--;
    }
    void Vector_insertAt(int index, T value)
    {
        if (index == this->CurrentSize - 1)
        {
            Vector_pushback(value);
        }
        else if (index > this->CurrentSize - 1)
        {
            std::cout << "Can't insert at this location" << std::endl;
        }
        else
        {

            if (this->Capacity == this->CurrentSize)
            {
                Vector_resize();
            }
            for (int i = this->CurrentSize - 1; i >= index; i--)
            {
                this->Arr[i + 1] = this->Arr[i];
            }
            this->Arr[index] = value;
            this->CurrentSize++;
        }
    }
    void Vector_insertMiddle(T value)
    {

        Vector_resize();
        int middleIndex = this->CurrentSize / 2;
        for (int i = this->CurrentSize - 1; i >= middleIndex; i--)
        {
            this->Arr[i + 1] = this->Arr[i];
        }
        this->Arr[middleIndex] = value;
        this->CurrentSize++;
    }
    void Vector_removeMiddle(void)
    {
        if (this->CurrentSize == 0)
        {
            std::cout << "Can't remove Empty Vector !!";
        }
        else
        {
            int middleIndex = this->CurrentSize / 2;
            for (int i = middleIndex; i < (this->CurrentSize - 1); i++)
            {
                this->Arr[i] = this->Arr[i + 1];
            }
            this->CurrentSize--;
        }
    }
    ~My_Vector()
    {
        delete[] Arr;
        std::cout << "Your Vector has been deleted\n";
    }
};
int main()
{
    My_Vector<int> v1(5, 3);
    v1.Vector_print();
    v1.Vector_insertMiddle(2);
    v1.Vector_print();
    v1.Vector_removeAt(4);
    v1.Vector_print();
    v1.Vector_insertAt(1, 10);
    v1.Vector_print();
    My_Vector<int> v2(v1);
    v2.Vector_print();
    v1.Vector_removeMiddle();
    v1.Vector_print();

    return 0;
}