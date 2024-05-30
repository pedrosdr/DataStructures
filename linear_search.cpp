#include <iostream>
#include "headers/print.h"

template <typename T>
int linearSearch(T* arr, int narr, T val)
{
    int temp = -1;
    for(int i = 0; i < narr; i++)
        if(arr[i] == val)
        {
            temp = i;
            break;
        }
    return temp;
}

int main(int argc, char* argv[])
{
    int arr[] = {2, 3, 4, 5, 6};
    print(linearSearch<int>(arr, 5, 2));
    return 0;
}