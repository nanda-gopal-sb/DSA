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

int main() {
  SingleLinkedList list;
  int choice, value, searchValue;

  do {
    std::cout << "\n1. Insert at start\n"
              << "2. Insert at end\n"
              << "3. Insert after value\n"
              << "4. Insert before value\n"
              << "5. Delete from start\n"
              << "6. Delete from end\n"
              << "7. Delete after value\n"
              << "8. Delete before value\n"
              << "9. Display list\n"
              << "0. Exit\n"
              << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "Enter value to insert: ";
        std::cin >> value;
        list.insertAtStart(value);
        break;
      case 2:
        std::cout << "Enter value to insert: ";
        std::cin >> value;
        list.insertAtEnd(value);
        break;
      case 3:
        std::cout << "Enter search value: ";
        std::cin >> searchValue;
        std::cout << "Enter new value: ";
        std::cin >> value;
        list.insertAfter(searchValue, value);
        break;
      case 4:
        std::cout << "Enter search value: ";
        std::cin >> searchValue;
        std::cout << "Enter new value: ";
        std::cin >> value;
        list.insertBefore(searchValue, value);
        break;
      case 5:
        list.deleteFromStart();
        break;
      case 6:
        list.deleteFromEnd();
        break;
      case 7:
        std::cout << "Enter value to delete after: ";
        std::cin >> value;
        list.deleteAfter(value);
        break;
      case 8:
        std::cout << "Enter value to delete before: ";
        std::cin >> value;
        list.deleteBefore(value);
        break;
      case 9:
        list.display();
        break;
      case 0:
        std::cout << "Exiting...\n";
        break;
      default:
        std::cout << "Invalid choice!\n";
    }
  } while (choice != 0);
  return 0;
}