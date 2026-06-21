// Editorial
class Solution {
  public:
    // Helper function to check if a tree is balanced and calculate its height
    bool isBalancedHelper(Node* root, int& height) {
        int leftHeight = 0, rightHeight = 0;
        if (!root) {
            height = 0;
            return true;
        }

        bool isLeftBalanced = isBalancedHelper(root->left, leftHeight);
        bool isRightBalanced = isBalancedHelper(root->right, rightHeight);

        height = max(leftHeight, rightHeight) + 1;

        // Check if the current node is balanced
        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return isLeftBalanced && isRightBalanced;
    }

    bool isBalanced(Node* root) {
        int height = 0;
        return isBalancedHelper(root, height);
    }
};

// My Solution
class Solution {
  public:
    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        // Code here
        if(!root) return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(isBalanced(root->left) && isBalanced(root->right)) {
            return abs(leftHeight-rightHeight) <= 1;
        }
        
        return false;
    }
};