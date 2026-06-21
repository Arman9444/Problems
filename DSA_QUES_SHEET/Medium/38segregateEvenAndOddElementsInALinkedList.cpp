class Solution {
public:
    Node* divide(Node* head) {
        if (!head || !head->next) return head; // Edge case: empty or single-node list
        
        Node* evenHead = nullptr; // Head of even nodes
        Node* evenTail = nullptr; // Tail of even nodes
        Node* oddHead = nullptr;  // Head of odd nodes
        Node* oddTail = nullptr;  // Tail of odd nodes
        
        Node* temp = head;
        
        // Traverse the list
        while (temp) {
            if (temp->data % 2 == 0) {
                // Add to the even list
                if (!evenHead) {
                    evenHead = evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            } else {
                // Add to the odd list
                if (!oddHead) {
                    oddHead = oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            }
            temp = temp->next;
        }
        
        // Connect even and odd lists
        if (evenTail) evenTail->next = oddHead; // If there are even nodes
        if (oddTail) oddTail->next = nullptr;  // Terminate the odd list
        
        return evenHead ? evenHead : oddHead; // Return the appropriate head
    }
};
