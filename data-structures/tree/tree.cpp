#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

template <typename T>
class Node
{
public: 
    T value;
    Node<T> *left;
    Node<T> *right;

    Node(T value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinarySearchTree
{
public:
    Node<T> *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    ~BinarySearchTree()
    {
        clear(root);
    }

    void clear(Node<T> *node)
    {
        if (node)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    bool isEmpty()
    {
        return this->root == nullptr;
    }

    void insert(T value)
    {
        Node<T> *n = new Node<T>(value);
        if (this->isEmpty())
        {
            this->root = n;
        }
        else
        {
            this->insertNode(this->root, n);
        }
    }

    void insertNode(Node<T> *root, Node<T> *newNode)
    {
        if (newNode->value < root->value)
        {
            if (root->left == nullptr)
            {
                root->left = newNode;
            }
            else
            {
                this->insertNode(root->left, newNode);
            }
        }
        else
        {
            if (root->right == nullptr)
            {
                root->right = newNode;
            }
            else
            {
                this->insertNode(root->right, newNode);
            }
        }
    }

    Node<T>* search(Node<T> *root, T value)
    {
        if (!root)
        {
            return nullptr;
        }
        else
        {
            if (root->value == value)
            {
                return root;
            }
            else if (value < root->value)
            {
                return this->search(root->left, value);
            }
            else
            {
                return this->search(root->right, value);
            }
        }
    }

    void preOrderTraversal(Node<T> *root)
    {
        if (root)
        {
            cout << root->value << endl;
            this->preOrderTraversal(root->left);
            this->preOrderTraversal(root->right);
        }
    }

    void inOrderTraversal(Node<T> *root)
    {
        if (root)
        {
            this->inOrderTraversal(root->left);
            cout << root->value << endl;
            this->inOrderTraversal(root->right);
        }
    }

    void postORderTraversal(Node<T> *root)
    {
        if (root)
        {
            this->postORderTraversal(root->left);
            this->postORderTraversal(root->right);
            cout << root << endl;
        }
    }

    void levelOrder()
    {
        if (!root)
            return;
        vector<Node<T> *> queue; 
        queue.push_back(root);   

        while (!queue.empty())
        {
            Node<T> *current = queue[0]; 
            queue.erase(queue.begin());  

            cout << current->value << endl;

            if (current->left)
            {
                queue.push_back(current->left);
            }

            if (current->right)
            {
                queue.push_back(current->right);
            }
        }
    }

    T max(Node<T>* root){
        if(!(root->right)){
            return root->value;
        }
        return this->max(root->right);   
    }

    T min(Node<T>* root){
        if(!(root->left)){
            return root->value;
        }
        return this->min(root->left);   
    }     

void deleteValue(T value){
    this->root = this->deleteNode(this->root, value);
}

Node<T>* deleteNode(Node<T>* root, T value){
    if(root == nullptr){
        return root;
    }

    if(value < root->value){
        root->left = this->deleteNode(root->left, value);
    } else if(value > root->value){
        root->right = this->deleteNode(root->right, value);
    } else {
        if(!root->left){
            return root->right; 
        }
        if(!root->right){
            return root->left;  
        }
        root->value = this->min(root->right);
        root->right = this->deleteNode(root->right, root->value);
    }

    return root;
}

    
};

int main()
{

    BinarySearchTree<int> *bt = new BinarySearchTree<int>();
    bt->insert(10);
    bt->insert(5);
    bt->insert(15);
    cout<<bt->min(bt->root);
    //bt->inOrderTraversal(bt->root);
    // bt->print();

    delete bt;
    return 0;
}
