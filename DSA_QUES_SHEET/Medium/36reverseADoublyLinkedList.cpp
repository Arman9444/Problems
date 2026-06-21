class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // If the list is empty or has only one node, return the head
        if (!head || !head->next) return head;

        DLLNode* curr = head;
        DLLNode* prevNode = NULL;

        // Traverse the list and swap next and prev pointers for each node
        while (curr) {
            DLLNode* temp = curr->next; // Store the original next node
            curr->next = curr->prev;   // Swap next and prev
            curr->prev = temp;         // Assign prev to the stored next node
            
            prevNode = curr;           // Move prevNode to current node
            curr = temp;               // Move to the next node in original order
        }

        // Return the new head (last node in the original list)
        return prevNode;
    }
};
