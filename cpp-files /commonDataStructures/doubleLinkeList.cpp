#include <iostream>

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
 private:
  Node* head;

 public:
  DoublyLinkedList() : head(nullptr) {}

  void insertAtHead(int val) {
    Node* newNode = new Node(val);
    if (head != nullptr) {
      head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
  }
  Node* getHead() { return head; }
  void insertAtTail(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
  void insertBefore(int key, int val) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
      temp = temp->next;
    }
    if (temp == nullptr) {
      std::cout << "Key not found\n";
      return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != nullptr) {
      temp->prev->next = newNode;
    } else {
      head = newNode;
    }
    temp->prev = newNode;
  }

  void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
      temp = temp->next;
    }
    if (temp == nullptr) {
      std::cout << "Key not found\n";
      return;
    }
    Node* newNode = new Node(val);
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != nullptr) {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
  }
  void deleteAtStart() {
    if (head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    }
    delete temp;
  }

  void deleteAtEnd() {
    if (head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    if (temp->prev != nullptr) {
      temp->prev->next = nullptr;
    } else {
      head = nullptr;
    }
    delete temp;
  }
  void updateHead(Node* ptr) { head = ptr; }
  void deleteRandomAfter(int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
      temp = temp->next;
    }
    if (temp == nullptr) {
      std::cout << "Key not found\n";
      return;
    }
    if (temp->prev != nullptr) {
      temp->prev->next = temp->next;
    } else {
      head = temp->next;
    }
    if (temp->next != nullptr) {
      temp->next->prev = temp->prev;
    }
    delete temp;
  }
  void deleteRandomBefore(int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
      temp = temp->next;
    }
    if (temp == nullptr || temp->prev == nullptr) {
      std::cout << "Key not found or no node before the key\n";
      return;
    }
    Node* nodeToDelete = temp->prev;
    if (nodeToDelete->prev != nullptr) {
      nodeToDelete->prev->next = temp;
    } else {
      head = temp;
    }
    temp->prev = nodeToDelete->prev;
    delete nodeToDelete;
  }
  void display() {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }
};

// int main() {
//   DoublyLinkedList dll;
//   int choice, value, key;

//   while (true) {
//     std::cout << "Menu:\n";
//     std::cout << "1. Insert at head\n";
//     std::cout << "2. Insert at tail\n";
//     std::cout << "3. Insert before a value\n";
//     std::cout << "4. Insert after a value\n";
//     std::cout << "5. Delete at start\n";
//     std::cout << "6. Delete at end\n";
//     std::cout << "7. Delete a node before a value\n";
//     std::cout << "8. Delete a node after a value\n";
//     std::cout << "9. Display list\n";
//     std::cout << "10. Exit\n";
//     std::cout << "Enter your choice: ";
//     std::cin >> choice;

//     switch (choice) {
//       case 1:
//         std::cout << "Enter value to insert at head: ";
//         std::cin >> value;
//         dll.insertAtHead(value);
//         break;
//       case 2:
//         std::cout << "Enter value to insert at tail: ";
//         std::cin >> value;
//         dll.insertAtTail(value);
//         break;
//       case 3:
//         std::cout << "Enter the key and value to insert before: ";
//         std::cin >> key >> value;
//         dll.insertBefore(key, value);
//         break;
//       case 4:
//         std::cout << "Enter the key and value to insert after: ";
//         std::cin >> key >> value;
//         dll.insertAfter(key, value);
//         break;
//       case 5:
//         dll.deleteAtStart();
//         break;
//       case 6:
//         dll.deleteAtEnd();
//         break;
//       case 7:
//         std::cout << "Enter the key to delete the node before: ";
//         std::cin >> key;
//         dll.deleteRandomBefore(key);
//         break;
//       case 8:
//         std::cout << "Enter the key to delete the node after: ";
//         std::cin >> key;
//         dll.deleteRandomAfter(key);
//         break;
//       case 9:
//         dll.display();
//         break;
//       case 10:
//         return 0;
//       default:
//         std::cout << "Invalid choice. Please try again.\n";
//     }
//   }

//   return 0;
// }