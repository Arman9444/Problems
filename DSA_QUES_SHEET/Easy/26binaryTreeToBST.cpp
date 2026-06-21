class Solution {
public:
    void getInorder(Node* root, vector<int>& nodes) {
        if (root == NULL) return;
        
        getInorder(root->left, nodes);
        
        nodes.push_back(root->data);
        
        getInorder(root->right, nodes);
    }

    void assignInorder(Node* root, vector<int>& nodes, int& index) {
        if (root == NULL) return;
        
        assignInorder(root->left, nodes, index);
        
        root->data = nodes[index++];
        
        assignInorder(root->right, nodes, index);
    }

    Node* binaryTreeToBST(Node* root) {
        if (root == NULL) return NULL;
        
        vector<int> nodes;
        
        getInorder(root, nodes);
        
        sort(nodes.begin(), nodes.end());
        
        int index = 0;
        assignInorder(root, nodes, index);
        
        return root;
    }
};