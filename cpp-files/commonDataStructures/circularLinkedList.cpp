#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int key) {
    data = key;
    next = nullptr;
  }
};

class circle {
 public:
  Node* start = nullptr;
  Node* last = nullptr;

 public:
  void insertStart(int key) {
    Node* newNode = new Node(key);
    if (start == nullptr) {
      start = newNode;
      last = start;
      return;
    }
    newNode->next = start;
    start = newNode;
    last->next = start;
  }
  void insertEnd(int key) {
    Node* newNode = new Node(key);
    if (start == nullptr) {
      start = newNode;
      last = start;
      return;
    }
    Node* temp = start;
    while (temp != last) {
      temp = temp->next;
    }
    temp->next = newNode;
    last = newNode;
    last->next = start;
  }
  void deleteEnd() {
    if (start == nullptr) {
      return;
    }
    if (start == last) {
      start = nullptr;
      last = nullptr;
      return;
    }
    Node* temp = start;
    while (temp->next != last) {
      temp = temp->next;
    }
    last = temp;
    last->next = start;
  }
  void display() {
    if (!start) {
      cout << "Bro this is NULL\n";
      return;
    }
    Node* temp = start;
    while (temp != last) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << temp->data << "->";
    cout << temp->next->data;
    cout << "\n";
  }
};
class circularQueue {
  circle C;

 public:
  void enqueue(int key) { C.insertEnd(key); }
  void dequeue() { C.deleteEnd(); }
};
