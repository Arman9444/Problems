#include <bits/stdc++.h>
using namespace std;

// Definition of a Node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to rearrange the linked list in Zig-Zag fashion
Node* zigZag(Node* head) {
    if (!head || !head->next) return head; // Base case

    bool shouldBeLess = true; // Start with the condition a <= b
    Node* current = head;

    while (current->next) {
        if (shouldBeLess) {
            // If current node is greater than the next node, swap them
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
            }
        } else {
            // If current node is less than the next node, swap them
            if (current->data < current->next->data) {
                swap(current->data, current->next->data);
            }
        }
        // Flip the condition for the next pair
        shouldBeLess = !shouldBeLess;

        // Move to the next node
        current = current->next;
    }

    return head;
}

// Utility function to create a linked list from a vector
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* tail = head;

    for (size_t i = 1; i < values.size(); ++i) {
        tail->next = new Node(values[i]);
        tail = tail->next;
    }

    return head;
}

// Utility function to print the linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver Code
int main() {
    vector<int> values = {11, 15, 20, 5, 10};

    Node* head = createLinkedList(values);

    head = zigZag(head);

    // Check if the output is correct
    printLinkedList(head);

    return 0;
}
