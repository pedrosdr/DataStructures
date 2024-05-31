#include <iostream>
#include "headers/print.h"

int binarySearch(int* arr, int narr, int val)
{
    int left = 0;
    int right = narr;
    int mid = (int) (right - left) / 2;
    while(left < right)
    {
        std::cout << left << " " << mid << " " << right << std::endl;

        if(val == arr[mid])
            return mid;

        if(left == mid)
            break;
        
        if(val < arr[mid])
            right = mid;
        else
            left = mid;

        mid = left + (int) (right - left) / 2;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    int arr[] = {2,3,4,5,6,7,8,66,71,89,102,303};
    int a = binarySearch(arr, 12, std::atoi(argv[1]));
    print(a);
    return 0;
}