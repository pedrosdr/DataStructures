#include <iostream>
#include "headers/print.h"

template<typename T>
void selectionSort(T* arr, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        
        if(min != i)
        {
            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main(int argc, char* argv[])
{
    float arr[] = {4.4, 2.1, 3.2, 5.7, 1.2, 6.7, 8.0, 9.1, 7.9};
    int n = 9;
    selectionSort(arr, n);

    // int n = 9;
    // for(int i = 0; i < n-1; i++)
    // {
    //     int min = i;
    //     for(int j = i+1; j < n; j++)
    //     {
    //         if(arr[j] < arr[min])
    //             min = j;
    //     }
        
    //     if(min != i)
    //     {
    //         int temp = arr[i];
    //         arr[i] = arr[min];
    //         arr[min] = temp;
    //     }
    // }

    for(int i = 0; i < n; i++)
    {
        print(arr[i]);
    }

    return 0;
}