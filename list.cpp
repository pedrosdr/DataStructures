#include <iostream>

template<typename T, typename R>
class Function
{
    public:
        virtual R call(T t) = 0;
};

template<typename T>
class Predicate
{
    public:
        virtual bool call(T t) = 0;
};

class CustomFunction1 : public Function<std::string, int>
{
    public:
        int call(std::string str) override
        {
            if(str == "Pedro")
                return 1;
            return 0;
        }
};

class CustomPredicate1: public Predicate<int>
{
    public:
        bool call(int obj) override
        {
            return obj == 1;
        }
};

template<typename T>
void print(T obj)
{
    std:: cout << obj << "\n";
};

template<typename T>
class List
{
    private:
        // Fields
        T* arr;
        int arrSize;
        int top;
    
    public:
        // Constructors / Destructors
        List() {
            arr = nullptr;
            arrSize = 0;
            top = -1;
        }

        ~List()
        {
            delete[] arr;
        }

        // Methods
        bool isEmpty()
        {
            return top == -1;
        }

        void display()
        {
            if(arrSize == 0)
            {
                std::cout << ">>[] size: 0\n";
                return;
            }

            std::cout << ">>[";
            for(int i = 0; i < arrSize; i++)
            {
                std::cout << arr[i];
                if(i != arrSize - 1)
                    std::cout << ", ";
            }
            std::cout << "] size: " << arrSize << "\n";
        }

        void push(T item)
        {
            T* narr = new T[arrSize + 1];
            for(int i = 0; i < arrSize; i++)
                narr[i] = arr[i];
            narr[arrSize] = item;

            delete[] arr;
            arr = narr;
            arrSize++;
            top++;
        }

        void pop()
        {
            if(isEmpty())
                return;

            if(top == 0)
            {
                arr = nullptr;
                top--;
                arrSize--;
                return;
            }

            T* narr = new T[arrSize - 1];
            for(int i = 0; i < arrSize - 1; i++)
                narr[i] = arr[i];

            delete[] arr;
            arr = narr;
            top--;
            arrSize--;
        }

        int count()
        {
            return arrSize;
        }

        T get(int pos)
        {
            if(top < pos || pos < 0)
                throw std::invalid_argument("Index out of bounds");
            
            return arr[pos];
        }

        void set(int pos, T val)
        {
            if(top < pos || pos < 0)
                throw std::invalid_argument("Index out of bounds");
            
            arr[pos] = val;
        }

        List<T>* loc(int start, int end)
        {
            if(start >= end || start < 0 ||  end > top)
                throw std::invalid_argument("Index out of bounds");

            List<T>* list = new List<T>();
            for(int i = start; i < end; i++)
                list->push(arr[i]);

            return list;
        }

        template<typename R>
        List<R>* map(Function<T, R>* mapping)
        {
            List<R>* list = new List<R>();

            for(int i = 0; i < arrSize; i++)
                list->push(mapping->call(arr[i]));
            
            delete mapping;
            return list;
        }

        List<T>* filter(Predicate<T>* condition)
        {
            List<T>* list = new List<T>();

            for(int i = 0; i < arrSize; i++)
            {
                if(condition->call(arr[i]))
                    list->push(arr[i]);
            }

            delete condition;
            return list;
        }
};


int main(int argc, char* argv[])
{
    List<std::string> list = List<std::string>();
    list.push("Pedro");
    list.push("Jaime");
    list.push("Divaldo");
    list.push("Pedro");
    list.push("Maria");
    list.push("Josefino");

    list.display();

    List<std::string>* other = list.loc(1, 4);
    other->display();

    List<int>* other2 = list.map<int>(new CustomFunction1());
    other2->display();

    List<int>* other3 = other2->filter(new CustomPredicate1());
    other3->display();

    delete other;
    delete other2;
    delete other3;
    return 0; 
}