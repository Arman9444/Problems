#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Function to delete nodes having greater value on the right
    Node* compute(Node* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Traverse and remove nodes not part of the result
        Node* maxNode = head;
        Node* curr = head;

        while (curr && curr->next) {
            if (curr->next->data < maxNode->data) {
                // Remove the next node
                curr->next = curr->next->next;
            } else {
                // Update maxNode and move to next
                curr = curr->next;
                maxNode = curr;
            }
        }

        // Step 3: Reverse the list back to its original order
        head = reverse(head);

        return head;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    Node* head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    Solution obj;
    head = obj.compute(head);

    printList(head);
    return 0;
}
