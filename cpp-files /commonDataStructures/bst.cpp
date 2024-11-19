#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
 public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
      root = newNode;
      return;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
      parent = current;
      if (value < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    if (value < parent->data) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
  }

  void inorderTraversal() { inorderTraversalHelper(root); }

  void preorderTraversal() { preorderTraversalHelper(root); }

  void postorderTraversal() { postorderTraversalHelper(root); }

 private:
  Node* root;

  void inorderTraversalHelper(Node* node) {
    if (node == nullptr)
      return;
    inorderTraversalHelper(node->left);
    std::cout << node->data << " ";
    inorderTraversalHelper(node->right);
  }

  void preorderTraversalHelper(Node* node) {
    if (node == nullptr)
      return;
    std::cout << node->data << " ";
    preorderTraversalHelper(node->left);
    preorderTraversalHelper(node->right);
  }

  void postorderTraversalHelper(Node* node) {
    if (node == nullptr)
      return;
    postorderTraversalHelper(node->left);
    postorderTraversalHelper(node->right);
    std::cout << node->data << " ";
  }
};

int main() {
  BinarySearchTree bst;
  int choice, value;

  do {
    std::cout << "\nMenu:\n";
    std::cout << "1. Insert\n";
    std::cout << "2. Inorder Traversal\n";
    std::cout << "3. Preorder Traversal\n";
    std::cout << "4. Postorder Traversal\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "Enter value to insert: ";
        std::cin >> value;
        bst.insert(value);
        break;
      case 2:
        std::cout << "Inorder Traversal: ";
        bst.inorderTraversal();
        std::cout << "\n";
        break;
      case 3:
        std::cout << "Preorder Traversal: ";
        bst.preorderTraversal();
        std::cout << "\n";
        break;
      case 4:
        std::cout << "Postorder Traversal: ";
        bst.postorderTraversal();
        std::cout << "\n";
        break;
      case 5:
        std::cout << "Exiting...\n";
        break;
      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 5);
  return 0;
}