// Editorial
class Solution {
  public:
    // Function to check if all leaf nodes are at the same level.
    bool ok(Node *root, int level, int *leafLevel) {

        // if tree is empty, return true
        if (root == NULL)
            return true;

        // if current node is a leaf node
        if (root->left == NULL && root->right == NULL) {

            // if leaf level is not set yet, set it and return true
            if (*leafLevel == 0) {
                *leafLevel = level;
                return true;
            }

            // if leaf level is already set, check if current level matches leaf level
            return (level == *leafLevel);
        }

        // recursively check if left and right subtrees satisfy the condition
        return ok(root->left, level + 1, leafLevel) &&
               ok(root->right, level + 1, leafLevel);
    }

    // Function to check if all leaf nodes are at the same level.
    bool check(Node *root) {
        int level = 0, leafLevel = 0;
        // call helper function and return the result
        return ok(root, level, &leafLevel);
    }
};

// my Solution
class Solution {
    int firstDepth = 0;
  public:
    /*You are required to complete this method*/
    bool check(Node *root) {
        // Your code here
        return helper(root, 0);
    }
    
    bool helper(Node* root, int currLevel) {
        if(!root) return true;
        
        if(root->left == NULL && root->right == NULL) {
            if(firstDepth == 0) {
                firstDepth = currLevel;
                return true;
            } else {
                return firstDepth == currLevel;
            }
        }
        
        if(!helper(root->left, currLevel+1)) return false;
        if(!helper(root->right, currLevel+1)) return false;
        
        return true;
    }
};