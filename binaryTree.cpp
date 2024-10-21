#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree class
class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    bool search(int value)
    {
        return searchRec(root, value);
    }

    void inOrder()
    {
        inOrderRec(root);
        cout << endl;
    }

    void preOrder()
    {
        preOrderRec(root);
        cout << endl;
    }

    void postOrder()
    {
        postOrderRec(root);
        cout << endl;
    }

private:
    Node *insertRight(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        node->right = insertRec(node->right, value);
        return node;
    }
    Node *insertRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    bool searchRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchRec(node->left, value);
        }
        else
        {
            return searchRec(node->right, value);
        }
    }

    void inOrderRec(Node *node)
    {
        if (node != nullptr)
        {
            inOrderRec(node->left);
            cout << node->data << " ";
            inOrderRec(node->right);
        }
    }

    void preOrderRec(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preOrderRec(node->left);
            preOrderRec(node->right);
        }
    }

    void postOrderRec(Node *node)
    {
        if (node != nullptr)
        {
            postOrderRec(node->left);
            postOrderRec(node->right);
            cout << node->data << " ";
        }
    }
};

// Main function to test the BinaryTree class
int main()
{
    BinaryTree tree;
    int lol = 0;
    while (1)
    {
        cout << "Enter the value" << "\n";
        cin >> lol;
        tree.insert(lol);
    }

    cout << "In-order traversal: ";
    tree.inOrder();

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    return 0;
}