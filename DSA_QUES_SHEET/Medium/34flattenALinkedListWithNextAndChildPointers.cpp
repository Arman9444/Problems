// C++ Program to flatten list with 
// next and child pointers 
#include <bits/stdc++.h> 
using namespace std; 

class Node { 
    public: 
    int data; 
    Node *next; 
    Node *child; 
    Node (int x) {
        data = x;
        next = nullptr;
          child = nullptr;
    }
}; 


// function that flattens 
// a multilevel linked list
void flattenList(Node *head) {
    
    // Base case
    if (head == nullptr) 
        return; 

    // Find tail node of first level
    Node *tail = head; 
    while (tail->next != nullptr) 
        tail = tail->next; 

    // One by one traverse through all nodes of first level 
    // linked list till we reach the tail node 
    Node *curr = head; 
    
    while (curr != nullptr) { 
        
        // If current node has a child 
        if (curr->child) { 
            
            // then append the child at the end of current list 
            tail->next = curr->child; 

            // and update the tail to new last node 
            Node* tmp = curr->child; 
            while (tmp->next) 
                tmp = tmp->next; 
            tail = tmp; 
            
            // Remove link between curr and child node
            curr->child = nullptr;
        } 

        // Change current node 
        curr = curr->next; 
    } 
} 

void printList(Node *head) { 
    Node* curr = head;
    while (curr != NULL) { 
        cout << curr->data << " "; 
        curr = curr->next; 
    } 
    cout<<endl; 
} 


int main() { 
  
      //Linked List - 
      // 1 -> 2 -> 3
    // |    |   
    // 4 -> 5   6
    // |
    // 7
  
    Node *head = new Node(1); 
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->child = new Node(4);
    head->child->next = new Node(5);
    head->next->next->child = new Node(6); 
    head->child->child = new Node(7);

    flattenList(head); 
    printList(head); 
    return 0; 
}