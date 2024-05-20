#include <iostream>

template<typename T>
void print(T obj)
{
    std::cout << obj << "\n";
}

class Queue
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
        Queue(int size)
        {
            arr = new int[size];
            front = -1;
            rear = -1;
            this->size = size;
            for(int i = 0; i < size; i++)
                arr[i] = 0;
        }

        ~Queue()
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
                if(i < front || i > rear)
                    std::cout << '.';
                else
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
            return rear == size - 1;
        }

        virtual void enqueue(int val)
        {
            if(isFull()) 
                return;

            if(isEmpty())
                front++;

            rear++;
            arr[rear] = val;
        }

        virtual void dequeue()
        {
            if(isEmpty()) return;

            if(front == rear)
            {
                arr[front] = 0;
                front = -1;
                rear = -1;
                return;
            }

            arr[front] = 0;
            front++;
        }

        int count()
        {
            if(isEmpty()) 
                return 0;

            return rear - front + 1;
        }
};

int main(int argc, char* argv[])
{
    Queue q = Queue(10);
    q.display();
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.dequeue();

    q.display();
    return 0;
}