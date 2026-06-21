// My Solution
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if(!head) return head;
        
        Node* curr = head; 
        Node* prev = NULL;
        set<int> s;
        
        while(curr) {
            if(s.find(curr->data) != s.end()) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                s.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};

// TLE
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if(!head) return head;
        
        Node* curr1 = head;
        
        while(curr1) {
            Node* curr2 = curr1;
            
            while(curr2->next) {
                if(curr2->next->data == curr1->data) {
                    Node* duplicate = curr2->next;
                    curr2->next = duplicate->next; // or curr2->next = curr2->next->next;
                    delete duplicate;
                } else {
                    curr2 = curr2->next;
                }
            }
            
            curr1 = curr1->next;
        }
        
        return head;
    }
};