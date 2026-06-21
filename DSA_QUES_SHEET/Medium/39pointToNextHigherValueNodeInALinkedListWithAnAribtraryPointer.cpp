#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node* arbitrary;

    Node(int val) {
        data = val;
        next = nullptr;
        arbitrary = nullptr;
    }
};

// Function to print the list along with arbitrary pointers
void printListWithArbitrary(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Data: " << temp->data;
        if (temp->arbitrary)
            cout << ", Arbitrary: " << temp->arbitrary->data << endl;
        else
            cout << ", Arbitrary: NULL" << endl;
        temp = temp->next;
    }
}

// Function to update the arbitrary pointers to the next higher value node
void setArbitraryPointers(Node* head) {
    if (!head) return;

    // Create a vector of all nodes
    vector<Node*> nodes;
    Node* temp = head;
    while (temp) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    // Sort the vector based on node values
    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return a->data < b->data;
    });

    // Update the arbitrary pointers
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->arbitrary = nodes[i + 1];
    }
    nodes[nodes.size() - 1]->arbitrary = nullptr; // Last node's arbitrary pointer remains NULL
}

int main() {
    // Create a sample linked list
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);

    // Set arbitrary pointers
    setArbitraryPointers(head);

    // Print the list with arbitrary pointers
    printListWithArbitrary(head);

    return 0;
}
