#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool match(string wild, string pattern) {
        int m = wild.size();
        int n = pattern.size();

        // Create a 2D DP table
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty wild and empty pattern match
        dp[0][0] = true;

        // Fill the first row for wild string containing '*'
        for (int i = 1; i <= m; ++i) {
            if (wild[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            } else {
                break;
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (wild[i - 1] == pattern[j - 1] || wild[i - 1] == '?') {
                    // Characters match or wild has '?'
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (wild[i - 1] == '*') {
                    // '*' can match zero or more characters
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    // Example 1
    string wild1 = "ge*ks";
    string pattern1 = "geeks";
    cout << (sol.match(wild1, pattern1) ? "Yes" : "No") << endl;

    // Example 2
    string wild2 = "ge?ks*";
    string pattern2 = "geeksforgeeks";
    cout << (sol.match(wild2, pattern2) ? "Yes" : "No") << endl;

    return 0;
}
