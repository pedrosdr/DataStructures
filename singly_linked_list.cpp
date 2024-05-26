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
            return "(key: " + std::to_string(key) + ", val: " + std::to_string(data) + ")";
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

        void insert(Node<T>* node, int pos)
        {
            if(pos < 0 || pos > size)
            {
                print("Could not insert node: index is out of the list");
                return;
            }

            if(nodeExists(node->Key()))
            {
                print("The node " + node->toString() + " was not inserted because it already exists.");
                return;
            }

            Node<T>* node1 = head;
            for(int i = 0; i < pos; i++)
                node1 = node1->Next();

            Node<T>* node2 = node1->Next();
            node1->Next(node);
            node->Next(node2);

            size++;
        }

        void append(Node<T>* node)
        {
            insert(node, size);
        }

        void prepend(Node<T>* node)
        {
            insert(node, 0);
        }

        Node<T>* remove(int pos)
        {
            if(pos < 0 || pos >= size)
            {
                print("Could not remove node: index is out of the list");
                return nullptr;
            }

            Node<T>* node1 = head;
            for(int i = 0; i < pos; i++)
                node1 = node1->Next();

            Node<T>* node2 = node1->Next();
            Node<T>* node3 = node2->Next();
            
            if(node3 != nullptr)
                node1->Next(node3);
            
            size--;
            return node2;
        }

        Node<T>* pop()
        {
            remove(size-1);
        }

        Node<T>* shift()
        {
            remove(0);
        }

        void update(int pos, T val)
        {
            if(pos < 0 || pos >= size)
            {
                print("Could not update node: index is out of the list");
                return;
            }

            Node<T>* node_i = head;
            for(int i = 0; i <= pos; i++)
                node_i = node_i->Next();
            
            node_i->Data(val);
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
            std::cout << "] size: " << size << "\n";
        }
};

int main(int argc, char* argv[])
{

    SiglyLinkedList<int> list = SiglyLinkedList<int>();
    Node<int>* first = new Node<int>(0,0);

    list.prepend(first);
    list.append(new Node<int>(1,1));
    // list.append(new Node<int>(2,2));
    // list.append(new Node<int>(3,3));
    // list.append(new Node<int>(1,4));

    list.insert(new Node<int>(9, 3), 1);
    list.prepend(new Node<int>(4, 3));
    list.insert(new Node<int>(5, 3), 1);
    list.display();

    // Node<int>* removed = list.remove(0);
    Node<int>* removed = list.shift();
    list.display();
    print(removed->toString());

    list.update(1, 20);
    list.display();

    delete removed;
    return 0;
}