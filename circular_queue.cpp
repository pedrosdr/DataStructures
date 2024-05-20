#include <iostream>
#include "headers/print.h"

class CircularQueue
{
    private:
        // Fields
        int front;
        int rear; 
        int* arr;
        int size;

        // Methods
        void clean()
        {
            for(int i = 0; i < size; i++)
            {
                arr[i] = 0;
            }
        }

    public:
        // Constructors / Destructors
        CircularQueue(int size)
        {
            arr = new int[size];
            front = -1;
            rear = -1;
            this->size = size;
            for(int i = 0; i < size; i++)
                arr[i] = 0;
        }

        ~CircularQueue()
        {
            delete[] arr;
        }

        // Properties

        // Methods
        void display()
        {
            std::cout << ">>[";
            
            for(int i = 0; i < size; i++)
            {
                std::cout << arr[i];

                if(i != size - 1)
                    std::cout << " ";
            }
            std::cout << "] size: " << count() << "\n";
        }

        bool isEmpty()
        {
            return front == -1 && rear == -1;
        }

        virtual bool isFull()
        {
            return (rear + 1)%size == front;
        }

        virtual void enqueue(int val)
        {
            if(isFull()) 
                return;

            if(isEmpty())
                front++;

            rear = (rear + 1)%size;
            arr[rear] = val;
        }

        virtual void dequeue()
        {
            if(isEmpty()) 
                return;

            if(front == rear)
            {
                arr[front] = 0;
                front = -1;
                rear = -1;
                return;
            }

            arr[front] = 0;
            front = (front + 1)%size;
        }

        int count()
        {
            if(isEmpty()) 
                return 0;

            if(front > rear)
                return size - (front - rear) + 1;
            
            return rear - front + 1;
        }
};

int main(int argc, char* argv[])
{
    CircularQueue q = CircularQueue(5);
    q.enqueue(5);
    q.display();

    q.enqueue(5);
    q.display();

    q.enqueue(5);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(5);
    q.display();

    q.enqueue(5);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(5);
    q.display();

    q.enqueue(5);
    q.display();

    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    q.enqueue(5);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(5);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(5);
    q.display();


    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
}