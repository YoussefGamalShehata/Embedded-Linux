#include <iostream>

struct vec
{
    int size;
    int Capacity;
    int * PtrToData;
};

vec * Vector_Create(int Size) //the user will pass the size not the capacity to reduce memory consumption
{
    vec * My_Vec = (vec *)malloc(sizeof(vec)); // Create Vector
    My_Vec->PtrToData = (int *)malloc(Size * sizeof(int)); // Create the array of data
    My_Vec->size = Size;
    My_Vec->Capacity = Size; // Corrected to set capacity separately
    return My_Vec;
}

void Vector_DeleteFromMemory(vec * My_Vec)
{
    if (NULL != My_Vec)
    {
        free(My_Vec->PtrToData);
        free(My_Vec);
    }
}

void Vector_PrintAllElements(vec * My_Vec)
{
    if (NULL != My_Vec)
    {
        std::cout << "Your Vector Data Collection: \n";
        for (int i = 0; i < My_Vec->size; i++)
        {
            printf("%d ", My_Vec->PtrToData[i]);
        }
        std::cout << std::endl;
    }
}

void Vector_PrintOneElement(vec * My_Vec, int Index)
{
    if (Index >= My_Vec->size || Index < 0)
    {
        std::cout << "Out Of Boundary!!" << std::endl;
    }
    else
    {
        printf("The %d Element is: %d\n", Index, My_Vec->PtrToData[Index]);
    }
}

void Vector_InsertOneElement(vec * My_Vec, int Index, int value)
{
    if (My_Vec->Capacity > My_Vec->size && Index == My_Vec->size) // Insert at the end
    {
        My_Vec->PtrToData[Index] = value;
        My_Vec->size++;
    }
    else
    {
        if (Index < 0 || Index > My_Vec->size)
        {
            std::cout << "Out of Boundaries" << std::endl;
        }
        else
        {
            if (My_Vec->size == My_Vec->Capacity) // Resize the vector to be double capacity if full
            {
                My_Vec->Capacity *= 2;
                My_Vec->PtrToData = (int *)realloc(My_Vec->PtrToData, My_Vec->Capacity * sizeof(int));
            }

            // Shift elements to the right to make space
            for (int i = My_Vec->size; i > Index; i--)
            {
                My_Vec->PtrToData[i] = My_Vec->PtrToData[i - 1];
            }

            // Add the new element
            My_Vec->PtrToData[Index] = value;
            My_Vec->size++;
        }
    }
}

void Vector_DeleteOneElement(vec * My_Vec, int Index)
{
    if (My_Vec->size == 0)
    {
        std::cout << "No Elements to delete" << std::endl;
    }
    else
    {
        if (Index < 0 || Index >= My_Vec->size)
        {
            std::cout << "Out of Boundaries" << std::endl;
        }
        else
        {
            // Shift elements to the left to fill the gap
            for (int i = Index; i < My_Vec->size - 1; i++)
            {
                My_Vec->PtrToData[i] = My_Vec->PtrToData[i + 1];
            }

            My_Vec->size--;
        }
    }
}

int main()
{
    int initialSize = 5;
    vec *myVector = Vector_Create(initialSize);

    // Initialize the vector with some values
    for (int i = 0; i < initialSize; i++)
    {
        myVector->PtrToData[i] = i + 1;
    }

    // Print all elements
    Vector_PrintAllElements(myVector);

    // Insert an element at a specific position
    std::cout << "\nInserting 99 at index 2" << std::endl;
    Vector_InsertOneElement(myVector, 2, 99);
    Vector_PrintAllElements(myVector);

    // Print a specific element
    std::cout << "\nPrinting element at index 2" << std::endl;
    Vector_PrintOneElement(myVector, 2);

    // Delete an element at a specific position
    std::cout << "\nDeleting element at index 2" << std::endl;
    Vector_DeleteOneElement(myVector, 2);
    Vector_PrintAllElements(myVector);

    // Clean up and delete vector from memory
    Vector_DeleteFromMemory(myVector);

    return 0;
}
