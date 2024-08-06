#include<iostream>
typedef int *(* CallBackFunc)(int ** PtrToArrayOfPtrs,int size,int * PtrToArrayOfSizes,int (Func)(int* x,int y));
int sum(int* x,int y)
{
    int sum=0;
    for(int i=0;i<y;i++)
    {
        sum +=x[i];
    }
    return sum;
}
int * SumArray (int ** PtrToArrayOfPtrs,int Array_size,int * PtrToArrayOfSizes,int (* Func)(int* x,int y))
{
    int * result = (int *)malloc(Array_size * sizeof(int));
    for(int i=0;i<Array_size;i++)
    {
        result[i] = Func(PtrToArrayOfPtrs[i],PtrToArrayOfSizes[i]);
    }
    return result;
}
int main()
{

     int size = 3;

    // Allocate memory for an array of pointers
    int** PtrToArrayOfPtrs = (int**)malloc(size * sizeof(int*));
    
    // Allocate memory for the array of sizes
    int* PtrToArrayOfSizes = (int*)malloc(size * sizeof(int));

    // Initialize arrays
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5};
    int array3[] = {6, 7, 8, 9};

    // Set pointers to arrays
    PtrToArrayOfPtrs[0] = array1;
    PtrToArrayOfPtrs[1] = array2;
    PtrToArrayOfPtrs[2] = array3;

    // Set sizes of arrays
    PtrToArrayOfSizes[0] = 3;
    PtrToArrayOfSizes[1] = 2;
    PtrToArrayOfSizes[2] = 4;

    // Call SumArray function
    int* result = SumArray(PtrToArrayOfPtrs, size, PtrToArrayOfSizes, sum);

    // Print the results
    for (int i = 0; i < size; i++)
    {
        std::cout << "Sum of array " << i+1 << ": " << result[i] << std::endl;
    }

    // Free allocated memory
    free(PtrToArrayOfPtrs);
    free(PtrToArrayOfSizes);
    free(result);



    return 0;
}