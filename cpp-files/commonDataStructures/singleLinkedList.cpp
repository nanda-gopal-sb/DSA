#include <iostream>

struct Node {
 public:
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {}
};

class SingleLinkedList {
 private:
  Node* head;

 public:
  SingleLinkedList() : head(nullptr) {}

  // Insert operations
  void insertAtStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }
  Node* getHead() { return head; }
  void insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
      head = newNode;
      return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void insertAfter(int searchValue, int newValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != searchValue) {
      temp = temp->next;
    }

    if (temp == nullptr) {
      std::cout << "Value " << searchValue << " not found\n";
      return;
    }

    Node* newNode = new Node(newValue);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertBefore(int searchValue, int newValue) {
    if (head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }

    if (head->data == searchValue) {
      insertAtStart(newValue);
      return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != searchValue) {
      temp = temp->next;
    }

    if (temp->next == nullptr) {
      std::cout << "Value " << searchValue << " not found\n";
      return;
    }

    Node* newNode = new Node(newValue);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Delete operations
  void deleteFromStart() {
    if (head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void deleteFromEnd() {
    if (head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
  }

  void deleteAfter(int searchValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != searchValue) {
      temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
      std::cout << "Cannot delete after " << searchValue << "\n";
      return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
  }

  void deleteBefore(int searchValue) {
    if (head == nullptr || head->next == nullptr) {
      std::cout << "Cannot delete before " << searchValue << "\n";
      return;
    }

    if (head->next->data == searchValue) {
      deleteFromStart();
      return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr &&
           temp->next->next->data != searchValue) {
      temp = temp->next;
    }

    if (temp->next->next == nullptr) {
      std::cout << "Value " << searchValue << " not found\n";
      return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
  }

  void display() {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }
    std::cout << "nullptr\n";
  }

  ~SingleLinkedList() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
};
