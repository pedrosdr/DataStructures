#include <iostream>
#include "headers/print.h"

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

        // Getters and Setters
        TreeNode<T>* Root() {return root;}
        TreeNode<T>* Root(TreeNode<T>* obj) {root = obj; return root;}

        // Methods
        bool isEmpty()
        {
            return root == nullptr;
        }

};


int main(int argc, char* argv[])
{
    TreeNode<int>* node = new TreeNode<int>(2);
    node->Left(new TreeNode<int>(1));
    node->Right(new TreeNode<int>(3));

    print(node->Value());
    TreeNode<int>* left = node->Left();
    // delete node;
    print(left->Value());

    BinarySearchTree<int> bst = BinarySearchTree<int>();
    print(bst.isEmpty());

    return 0;
}