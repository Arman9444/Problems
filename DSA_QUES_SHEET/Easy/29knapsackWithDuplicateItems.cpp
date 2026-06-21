class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<int> dp(capacity+1, 0);
        
        for(int i=1; i<=capacity; i++) { 
            for(int j=0; j<n; j++) {
                if(wt[j] <= i) {
                    dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
                }
            }
        }
        
    return dp[capacity];
    }
};