class Solution {
  public:
    // Helper function for DFS
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans) {
        // Mark the current node as visited
        vis[node] = true;
        // Add the node to the answer
        ans.push_back(node);
        
        // Visit all the neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                // Recursively visit the unvisited neighbors
                dfs(neighbor, adj, vis, ans);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();  // Number of vertices
        vector<bool> vis(V, false);  // Visited array
        vector<int> ans;  // Result array to store DFS traversal
        
        // Start DFS from vertex 0
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};