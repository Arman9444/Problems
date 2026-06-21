class Solution {
  public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del_node) {
        // Your code here
        
        if(del_node == NULL || del_node->next == NULL) {
            return;
        }
        
        Node* temp = del_node->next;
        
        del_node->data = temp->data;
        del_node->next = temp->next;
        
        delete temp;
    }
};

// This works too. but not a great solution as the node is not being deleted.
class Solution {
  public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del_node) {
        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
    }
};