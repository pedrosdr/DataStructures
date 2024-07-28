#include <iostream>
#include <vector>
#include "headers/print.h"

using std::cout;
using std::string;
using std::vector;

template <typename T>
class TreeNode
{
    private:
        // Fields
        T value;
        TreeNode<T>* left;
        TreeNode<T>* right;
    
    public:
        // Constructors / Destructor
        TreeNode()
        {
            value = T();
            left = nullptr;
            right = nullptr;
        }

        TreeNode(T value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }

        ~TreeNode() 
        {
            if(left != nullptr)
                delete left;

            if(right != nullptr)
                delete right;
        }

        // Getters and Setters
        T Value() {return value;}
        T Value(T obj) {value = obj; return value;}
        
        TreeNode<T>* Left() {return left;}
        TreeNode<T>* Left(TreeNode<T>* obj) {left = obj; return left;}

        TreeNode<T>* Right() {return right;}
        TreeNode<T>* Right(TreeNode<T>* obj) {right = obj; return right;}

        // Methods
        void print() 
        {
            print(0);
        }

        void print(int n)
        {
            if(right != nullptr)
                right->print(n+1);

            for(int i = 0; i < n; i++)
                cout << "    ";
            cout << "|->(" << value << ")\n";

            if(left != nullptr)
                left->print(n+1);
        }
};

template<typename T>
class BinarySearchTree
{
    private:
        // Fields
         TreeNode<T>* root;

    public:
        // Constructors / Destructor
        BinarySearchTree()
        {
            root = nullptr;
        }

        BinarySearchTree(TreeNode<T>* root)
        {
            this->root = root;
        }

        ~BinarySearchTree()
        {
            if(root != nullptr)
                delete root;
        }

        // Methods
        bool isEmpty()
        {
            return root == nullptr;
        }

        bool contains(TreeNode<T>* node)
        {
            if(isEmpty())
                return false;
            
            TreeNode<T>* temp = root;
            while (temp != nullptr)
            {
                if(temp->Value() == node->Value())
                    return true;
                else if(node->Value() > temp->Value() && temp->Right() == nullptr)
                    return false;
                else if(node->Value() < temp->Value() && temp->Left() == nullptr)
                    return false;
                else if(node->Value() > temp->Value()) {
                    temp = temp->Right();
                    continue;
                }
                else {
                    temp = temp->Left();
                    continue;
                }

                return false;
            }
            

        }

        void insert(vector<T> &vect)
        {
            for(int i = 0; i < vect.size(); i++)
            {
                TreeNode<T>* node = new TreeNode<T>(vect.at(i));
                if(contains(node))
                {
                    delete node;
                    continue;
                }

                insert(node);
            }
        }

        void insert(TreeNode<T>* node)
        {
            if(isEmpty())
            {
                root = node;
                return;
            }

            TreeNode<T>* temp = root;
            while(temp != nullptr) 
            {
                if(node->Value() == temp->Value())
                    break;

                if(temp->Left() == nullptr && node->Value() < temp->Value())
                {
                    temp->Left(node);
                    break;
                }

                if(temp->Right() == nullptr && node->Value() > temp->Value())
                {
                    temp->Right(node);
                    break;
                }

                if(node->Value() < temp->Value())
                {
                    temp = temp->Left();
                    continue;
                }
                else
                {
                    temp = temp->Right();
                    continue;
                }
            }
        }

        void print()
        {
            cout << "----------------------------------------\n";
            cout << "---------  Binary Tree Search  ---------\n";
            cout << "----------------------------------------\n";

            if(root != nullptr)
                root->print();
            else
                cout << "---------         Empty        ---------\n";

            cout << "----------------------------------------\n";
        }

};


int main(int argc, char* argv[])
{
    vector<int> vect = {22, 4, 6, 34, 54, 12, 15, 77, 65, 67, 9, 9, 1, 3, 3, 23, 45, 66};
    BinarySearchTree<int> tree = BinarySearchTree<int>();
    tree.insert(vect);
    tree.print();
    cout << tree.contains(new TreeNode<int>(71));

    return 0;
}