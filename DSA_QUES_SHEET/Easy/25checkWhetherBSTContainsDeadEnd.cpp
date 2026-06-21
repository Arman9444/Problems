class Solution {
public:
    bool isDeadEndUtil(Node* root, int min, int max) {
        if (root == NULL) return false;

        // Dead-end condition: If min equals max, no more numbers can fit.
        if (min == max) return true;

        // Recur for left and right subtrees with updated ranges
        return isDeadEndUtil(root->left, min, root->data - 1) || 
               isDeadEndUtil(root->right, root->data + 1, max);
    }

    bool isDeadEnd(Node* root) {
        return isDeadEndUtil(root, 1, INT_MAX);
    }
};