#include <iostream>
#include "../commonDataStructures/singleLinkedList.cpp"
using namespace std;

SingleLinkedList LL;

void reverse() {
  Node* temp = LL.getHead();
  Node* next;
  Node* prev = nullptr;
  while (temp != nullptr) {
    next = temp->next;
    // Reverse current node's next pointer
    temp->next = prev;
    next->next = temp;
    prev = temp;
    temp = next;
  }
}

int main(int argc, char const* argv[]) {
  LL.insertAtEnd(2);
  LL.insertAtEnd(3);
  LL.insertAtEnd(4);
  LL.insertAtEnd(5);
  LL.insertAtEnd(6);
  LL.insertAtEnd(7);
  cout << "Before" << "\n";
  LL.display();
  reverse();
  LL.display();
}
