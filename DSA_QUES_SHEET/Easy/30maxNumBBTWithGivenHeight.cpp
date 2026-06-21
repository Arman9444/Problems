class Solution {
  public:
    int countBT(int h) {
        // Define a large prime modulus for the result (to avoid overflow)
        const int MOD = 1000000007;
        
        // DP array to store the number of balanced binary trees for each height
        vector<long long> dp(h + 1, 0);
        
        // Base cases
        dp[0] = dp[1] = 1;
        
        // Calculate number of BBTs for each height from 2 to h
        for (int i = 2; i <= h; i++) {
            // Recurrence relation: dp[i] = dp[i-1]^2 + 2 * dp[i-1] * dp[i-2]
            dp[i] = (dp[i-1] * dp[i-1] + 2 * dp[i-1] * dp[i-2]) % MOD;
        }
        
        // Return the number of balanced binary trees of height h
        return dp[h];
    }
};