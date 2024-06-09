#include <iostream>
#include "headers/print.h"

template <typename T>
void insertionSort(T* arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i-1;
        while(j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char* argv[])
{
    float arr[] = {4.4, 2.1, 3.2, 5.7, 1.2, 6.7, 8.0, 9.1, 7.9};
    int n = 9;

    insertionSort(arr, n);
    
    for(int i = 0; i < n; i++)
        print(arr[i]);

    return 0;
}