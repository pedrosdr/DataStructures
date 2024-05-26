#include <iostream>
#include <cmath>
#include "headers/print.h"

template<typename T>
class ArrayList
{
    private:
        // Fields
        T* arr;
        int minimumCapacity;
        int top;
        int capacity;
        int size;
        float grouthRate;

    public:
        // Constructors / Destructors
        ArrayList()
        {
            minimumCapacity = 10;
            capacity = minimumCapacity;
            size = 0;
            grouthRate = 1.5;
            arr = new T[capacity];
        }
        ~ArrayList()
        {
            delete[] arr;
        }

        // Methods
        void displayRaw()
        {
            std::cout << ">>[";
            for(int i = 0; i < capacity; i++)
            {
                std::cout << arr[i];
                if(i != capacity - 1)
                    std::cout << ", ";
            }
            std::cout << "] capacity: " << capacity << ", size: " << size << "\n";
        }

        void display()
        {
            std::cout << ">>[";
            for(int i = 0; i < size; i++)
            {
                std::cout << arr[i];
                if(i != size - 1)
                    std::cout << ", ";
            }
            std::cout << "] size: " << size << "\n";
        }

        bool isFull()
        {
            return size == capacity;
        }

        void expand()
        {
            int newCapacity = ceil(capacity * grouthRate);
            T* newArr = new T[newCapacity];
            for(int i = 0; i < size; i++)
                newArr[i] = arr[i];
            delete arr;
            arr = newArr;
            capacity = newCapacity;
        }

        void contract()
        {
            int newCapacity = ceil(capacity / grouthRate);

            if(newCapacity < minimumCapacity)
                newCapacity = minimumCapacity;

            capacity = newCapacity;
            T* newArr = new T[capacity];

            for(int i = 0; i < capacity; i++)
                newArr[i] = arr[i];

            delete[] arr;
            arr = newArr;
        }

        void append(T val)
        {
            if(isFull())
                expand();
            
            arr[size] = val;
            size++;
        }

        void pop()
        {
            if(size <= 0)
                return;

            size--;

            if(capacity > minimumCapacity && size < ceil(capacity / grouthRate))
                contract();
        }
};

int main(int argc, char* argv[])
{
    ArrayList<int> arr = ArrayList<int>();


    arr.displayRaw();
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.displayRaw();
    arr.append(2);
    arr.append(2);
    arr.append(2);
    arr.append(2);
    arr.append(2);
    arr.append(2);
    arr.displayRaw();
    arr.pop();
    arr.displayRaw();
    arr.pop();
    arr.displayRaw();
    arr.pop();
    arr.displayRaw();
    arr.pop();
    arr.displayRaw();
    arr.pop();
    arr.displayRaw();
    arr.pop();
    arr.displayRaw();
    return 0;
}