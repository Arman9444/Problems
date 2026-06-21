class Solution {
public:
    // Helper function to perform DFS
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        // Boundary check and check if the cell is water or already visited
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') {
            return;
        }

        // Mark the cell as visited
        grid[i][j] = '0';

        // Directions for 8 possible movements
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (auto& dir : directions) {
            dfs(grid, i + dir[0], j + dir[1], n, m);
        }
    }

    // Function to find the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        int count = 0; // To count the number of islands

        // Traverse each cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If the cell is land ('1'), start a DFS
                if (grid[i][j] == '1') {
                    ++count; // Found a new island
                    dfs(grid, i, j, n, m); // Mark all connected land as visited
                }
            }
        }

        return count; // Return the total number of islands
    }
};
