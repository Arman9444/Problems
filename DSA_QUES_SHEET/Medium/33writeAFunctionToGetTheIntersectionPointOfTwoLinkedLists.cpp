class Solution {
  public:
    // Function to find the intersection point of two linked lists
    Node* intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return NULL;

        // Calculate the lengths of both lists
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1) {
            len1++;
            temp1 = temp1->next;
        }

        while (temp2) {
            len2++;
            temp2 = temp2->next;
        }

        // Align the lists
        temp1 = head1;
        temp2 = head2;

        if (len1 > len2) {
            int diff = len1 - len2;
            while (diff--) temp1 = temp1->next;
        } else if (len2 > len1) {
            int diff = len2 - len1;
            while (diff--) temp2 = temp2->next;
        }

        // Traverse together to find the intersection point
        while (temp1 && temp2) {
            if (temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL; // No intersection point
    }
};
