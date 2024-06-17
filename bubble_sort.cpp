#include <iostream>
#include "headers/print.h"
using std::cout;

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp; 
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        bool ordered = true;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j+1] < arr[j])
            {
                ordered = false;
                swap(arr[j+1], arr[j]);
            }
            print(arr,n);
        }
        if(ordered)
            break;
    }
}

int main(int argc, char* argv[])
{
    // int arr[] = {10, 3, 5, 2, 6, 7, 9, 4, 5, 9, 8, 2, 1, 7};
    int arr[] = {2,1,4,3,5};
    int n = 5;
    print(arr, n);
    bubbleSort(arr, n);
    print(arr,n);

    return 0;
}