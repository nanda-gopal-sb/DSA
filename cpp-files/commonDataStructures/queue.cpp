#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Queue {
 private:
  Node* front;
  Node* rear;

 public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  ~Queue() {
    while (front != nullptr) {
      Node* temp = front;
      front = front->next;
      delete temp;
    }
  }

  void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (rear == nullptr) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
    cout << "Enqueued " << value << endl;
  }

  void dequeue() {
    if (front == nullptr) {
      cout << "Queue is empty" << endl;
      return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    }
    cout << "Dequeued " << temp->data << endl;
    delete temp;
  }

  void display() {
    if (front == nullptr) {
      cout << "Queue is empty" << endl;
      return;
    }
    Node* temp = front;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  Queue q;
  int choice, value;

  do {
    cout << "\nQueue Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to enqueue: ";
        cin >> value;
        q.enqueue(value);
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        q.display();
        break;
      case 4:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice, please try again." << endl;
    }
  } while (choice != 4);

  return 0;
}