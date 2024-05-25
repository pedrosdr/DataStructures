#include <iostream>
#include "headers/print.h"

template <typename T>
class Node
{
    private:
        // Fields
        int key;
        T data;
        Node* next;

    public:
        // Constructors / Destructors
        Node() {
            key = -1;
            data = T();
            next = nullptr;
        }
        Node(int key, T data)
        {
            this->key = key;
            this->data = data;
        }
        Node(int key, T data, Node* next)
        {
            this->key = key;
            this->data = data;
            this->next = next;
        }
        ~Node() {}
    
        // Properties
        int Key() {return key;}
        int Key(int val) {key = val; return key;}

        T Data() {return data;}
        T Data(int val) {data = val; return data;}

        Node* Next() {return next;}
        Node* Next(Node* val) {next = val; return next;}

        // Methods
        std::string toString()
        {
            return "<key: " + std::to_string(key) + ">";
        }
};

template<typename T>
class SiglyLinkedList
{
    private:
        // Fields
        Node<T>* head;
        int size;

    public:
        // Constructors and Destructors
        SiglyLinkedList() 
        {
            head = new Node<T>();
            size = 0;
        }
        ~SiglyLinkedList()
        {
            for(int i = size; i >=0; i--)
            {
                Node<T>* node = head;
                for(int j = 0; j < i; j++)
                {
                    node = node->Next();
                }
                delete node;
            }
        }

        // Properties
        Node<T>* Head() {return head;}

        // Methods
        bool nodeExists(int key)
        {
            Node<T>* node_i = head;
            for(int i = 0; i < size; i++)
            {
                node_i = node_i->Next();
                if(node_i->Key() == key)
                    return true;
            }
            return false;
        }

        void append(Node<T>* node)
        {
            if(nodeExists(node->Key()))
            {
                print("The node " + node->toString() + " was not appended because it already exists.");
                return;
            }

            Node<T>* node_i = head;
            for(int i = 0; i < size; i++)
            {
                node_i = node_i->Next();
            }
            node_i->Next(node);
            size++;
        }

        void display()
        {
            std::cout << ">>[";
            Node<T>* node_i = head;
            for(int i = 0; i < size; i++)
            {
                node_i = node_i->Next();
                std::cout << node_i->toString();
                if(i != size - 1)
                    std::cout << ", ";
            }
            std::cout << "] size: " << size;
        }
};

int main(int argc, char* argv[])
{

    SiglyLinkedList<int> list = SiglyLinkedList<int>();
    Node<int>* first = new Node<int>(0,0);

    list.append(first);
    list.append(new Node<int>(1,1));
    list.append(new Node<int>(2,2));
    list.append(new Node<int>(3,3));
    list.append(new Node<int>(1,4));
    list.display();

    return 0;
}