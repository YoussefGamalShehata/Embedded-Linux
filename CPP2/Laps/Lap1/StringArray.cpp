#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;




int main()
{
    int n = 0;
    cout << "Please The Number of Strings : ";
    cin>> n;


    char **arr;
    

    arr = (char**)malloc(n * sizeof(char*));

    for(int i =0; i < n; i++)
    {
        arr[i] = (char*)malloc(30);

    }

    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i =0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    free(arr);

}