#include <iostream>
#include <string>

template<typename T>
void print(T obj)
{
    std::cout << obj << "\n";
}

template<typename T>
T input()
{
    T obj;
    std::cin >> obj;
    return obj; 
}

class Stack {
    private:
        // Fields
        int top;
        int* arr;
        int arrSize;

    public:
        // Constructors
        Stack()
        {
            Stack(5);
        }

        Stack(int arrSize)
        {
            top = -1;
            arr = new int[arrSize];
            this->arrSize = arrSize;

            for(int i = 0; i < arrSize; i++)
            {
                arr[i] = 0;
            }
        }

        ~Stack()
        {
            delete[] arr;
        }

        // Methods
        void display()
        {
            std::cout << ">> [";
            
            for(int i = 0; i <= top; i++)
            {
                std::cout << arr[i];
                if(i != top)
                    std::cout << " ";
            }
            std::cout << "]\n";
        }

        bool isEmpty()
        {
            return top == -1;
        }

        bool isFull()
        {
            return top == arrSize - 1;
            if(top == arrSize - 1)
                return true;
            return false;
        }

        void push(int val)
        {
            if(isFull())
            {
                print("The stack is full!");
                return;
            }
            
            top++;
            arr[top] = val;
        }

        void pop()
        {
            if(isEmpty())
            {
                print("The stack is empty!");
                return;
            }

            arr[top] = 0;
            top--;
        }

        int count()
        {
            return top + 1;
        }

        int peek(int pos)
        {
            if(top < pos)
            {
                print("Stack underflow!\n");
                return 0;
            }

            return arr[pos];
        }

        void change(int pos, int val)
        {
            if(top < pos)
            {
                print("Stack underflow!\n");
                return;
            }

            arr[pos] = val;
        }
};

int main(int argc, char* argv[])
{
    Stack stk = Stack(std::atoi(argv[1]));
    
    stk.display();
    stk.push(input<int>());
    stk.push(input<int>());
    stk.push(input<int>());
    stk.display();

    return 0;
}