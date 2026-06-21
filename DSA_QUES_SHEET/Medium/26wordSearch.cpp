class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};


// or
class Solution {
public:
    // Main function to find if word exists
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Start DFS from each cell in the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    // Helper DFS function to search the word in the board
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // If all characters in the word are found
        if (index == word.length()) {
            return true;
        }
        
        // Check if out of bounds or character doesn't match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Temporarily mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore the four possible directions (up, down, left, right)
        bool found = dfs(board, word, i + 1, j, index + 1) || 
                     dfs(board, word, i - 1, j, index + 1) || 
                     dfs(board, word, i, j + 1, index + 1) || 
                     dfs(board, word, i, j - 1, index + 1);
                         
        // Restore the cell after backtracking
        board[i][j] = temp;
        
        return found;
    }
};
