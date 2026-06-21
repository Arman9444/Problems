// C++ program to sort bitonic DLL.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to sort a bitonic doubly linked list
Node* sortBitonicDLL(Node* head) {
    if (!head || !head->next) return head;

    // Find the last node
    Node* last = head;
    while (last->next) {
        last = last->next;
    }

    // Initialize pointers
    Node* front = head;
    Node* result = nullptr;
    Node* tail = nullptr;

    // Process nodes until all are added to the result list
    while (front != nullptr && last != nullptr && 
           front != last && last->next != front) {
      
        Node* newNode = nullptr;

        // Compare the value of the front and last nodes
        if (front->data < last->data) {
            newNode = new Node(front->data);
            front = front->next;
        } else {
            newNode = new Node(last->data);
            last = last->prev;
        }

        // Add the new node to the result list
        if (!result) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }

    // Handle the case where front and last pointers
      // meet or cross
    while (front != nullptr && front != last->next) {
        Node* newNode = new Node(front->data);
        front = front->next;
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    while (last != nullptr && last->next != front) {
        Node* newNode = new Node(last->data);
        last = last->prev;
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    return result;
}

int main() {
  
    // Create the doubly linked list:
    // 2<->12<->11<->1
    Node* head = new Node(2);
    head->next = new Node(12);
    head->next->prev = head;
    head->next->next = new Node(11);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(1);
    head->next->next->next->prev = head->next->next;

    Node* sortedHead = sortBitonicDLL(head);

    printList(sortedHead);

    return 0;
}