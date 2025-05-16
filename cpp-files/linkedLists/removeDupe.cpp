#include <iostream>
#include "../commonDataStructures/doubleLinkeList.cpp"
using namespace std;
DoublyLinkedList Dl;
void deleteNode(int key, Node* startFromHere) {
  Node* head = Dl.getHead();
  if (head == nullptr) {
    return;
  }
  Node* temp = startFromHere;
  while (temp != nullptr && temp->data != key) {
    temp = temp->next;
  }
  if (temp == nullptr) {
    return;
  }
  if (temp == head) {
    if (head->next == nullptr) {
      head = nullptr;
    } else {
      head = head->next;
      Dl.updateHead(head);
    }
    return;
  }
  if (temp->next == nullptr) {
    temp = temp->prev;
    temp->next = nullptr;
    return;
  }
  temp = temp->prev;
  temp->next = temp->next->next;
  temp->next->prev = temp;
}
int getCount(int key) {
  int count = 0;
  Node* temp = Dl.getHead();
  for (; temp != nullptr; temp = temp->next) {
    if (temp->data == key) {
      count++;
    }
  }
  return count;
}
void removeDupe() {
  Node* head = Dl.getHead();
  Node* temp = head;
  for (; temp != nullptr; temp = temp->next) {
    int curr = temp->data;
    if (getCount(curr) == 1) {
      continue;
    } else {
      while (getCount(curr) != 1) {
        deleteNode(curr, temp->next);
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  int lol;
  for (int i = 0; i < 5; i++) {
    cin >> lol;
    Dl.insertAtTail(lol);
  }
  Dl.display();
  removeDupe();
  Dl.display();
  return 0;
}