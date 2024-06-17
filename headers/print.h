template<typename T>
void print(T obj)
{
    std::cout << obj << "\n";
}

template<typename T>
void print(T arr[], int n)
{
    std::cout << "[";
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if(i != n-1)
            std::cout << ", ";
    }
    std::cout << "]\n";
}