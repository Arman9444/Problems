class Solution {
public:
    void dfs(vector<vector<char>>& mat, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != 'O') {
            return;
        }

        // Mark as safe
        mat[i][j] = 'S';

        // Explore all 4 directions
        dfs(mat, i + 1, j, n, m);
        dfs(mat, i - 1, j, n, m);
        dfs(mat, i, j + 1, n, m);
        dfs(mat, i, j - 1, n, m);
    }

    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Mark boundary-connected 'O' cells
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 'O') dfs(mat, i, 0, n, m);
            if (mat[i][m - 1] == 'O') dfs(mat, i, m - 1, n, m);
        }

        for (int j = 0; j < m; ++j) {
            if (mat[0][j] == 'O') dfs(mat, 0, j, n, m);
            if (mat[n - 1][j] == 'O') dfs(mat, n - 1, j, n, m);
        }

        // Replace all 'O' with 'X', and 'S' back to 'O'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if (mat[i][j] == 'S') {
                    mat[i][j] = 'O';
                }
            }
        }

        return mat;
    }
};
