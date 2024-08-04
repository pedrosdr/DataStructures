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

        // methods
        void printPreOrder(TreeNode<T>* node)
        {
            if(node == nullptr) return;
            cout << node->Value() << " ";
            printPreOrder(node->Left());
            printPreOrder(node->Right());
        }

        void printInOrder(TreeNode<T>* node)
        {
            if(node == nullptr) return;
            printInOrder(node->Left());
            cout << node->Value() << " ";
            printInOrder(node->Right());
        }

        void printPostOrder(TreeNode<T>* node)
        {
            if(node == nullptr) return;
            printPostOrder(node->Left());
            printPostOrder(node->Right());
            cout << node->Value() << " ";
        }

        void printReverseOrder(TreeNode<T>* node)
        {
            if(node == nullptr) return;
            printReverseOrder(node->Right());
            cout << node->Value() << " ";
            printReverseOrder(node->Left());
        }

        TreeNode<T>* seek(TreeNode<T>* node, int value)
        {
            if(node == nullptr || node->Value() == value)
                return node;
            
            if(value < node->Value())
                return seek(node->Left(), value);

            return seek(node->Right(), value);
        }

        int height(TreeNode<T>* node) 
        {
            if(node == nullptr)
                return -1;
            
            int left_height = height(node->Left());
            int right_height = height(node->Right());

            if(left_height > right_height)
                return left_height + 1;
            
            return right_height + 1;
        }

        void printLevelOrderBFS(TreeNode<T>* node)
        {
            int h = height(node);
            for(int i = 0; i <= h; i++)
                printGivenLevel(node, i);
        }

        void printGivenLevel(TreeNode<T>* node, int level)
        {
            if(node == nullptr) return;

            if(level == 0)
                std::cout << node->Value() << " ";
            else {
                printGivenLevel(node->Left(), level - 1);
                printGivenLevel(node->Right(), level - 1);
            }
            
        }

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

        void printPreOrder()
        {
            cout << "Pre:     ";
            printPreOrder(root);
            cout << "\n";
        }

        void printInOrder()
        {
            cout << "In:      ";
            printInOrder(root);
            cout << "\n";
        }

        void printPostOrder()
        {
            cout << "Post:    ";
            printPostOrder(root);
            cout << "\n";
        }

        void printReverseOrder()
        {
            cout << "Reverse: ";
            printReverseOrder(root);
            cout << "\n";
        }

        TreeNode<T>* lookup(T value)
        {
            if(isEmpty()) return nullptr;

            TreeNode<T>* temp = root;
            TreeNode<T>* node = nullptr;
            while(temp != nullptr)
            {
                if(value == temp->Value())
                {
                    node = temp;
                    break;
                }
                
                if(value < temp->Value())
                {
                    temp = temp->Left();
                    continue;
                }

                temp = temp->Right();
            }

            return node;
        }

        TreeNode<T>* seek(T value)
        {
            return seek(root, value);
        }

        int height()
        {
            return height(root);
        }

        void printLevelOrderBFS()
        {
            printLevelOrderBFS(root);
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
    vector<int> vect = {30, 18, 45, 10, 25, 65};
    BinarySearchTree<int> tree = BinarySearchTree<int>();
    tree.insert(vect);
    tree.print();
    // cout << tree.contains(new TreeNode<int>(71));
    tree.printPreOrder();
    tree.printInOrder();
    tree.printPostOrder();
    tree.printReverseOrder();
    cout << tree.lookup(25)->Value() << "\n";
    cout << tree.seek(10)->Value() << "\n";

    vect = {30, 18, 45, 10, 25};
    tree = BinarySearchTree<int>();
    tree.insert(vect);
    tree.print(); 
    cout << tree.height() << "\n";
    tree.printLevelOrderBFS();
    return 0;
}