// my solution
class Solution {
  public:
    int longestSubseq(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(abs(arr[i] - arr[j]) == 1) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

// memoization
class Solution{
public:
    int solve(int ind,int prev,int n,int nums[],vector<vector<int>> &dp)
    {
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }
       
        int take = 0, nottake = 0;

        if (prev == -1 || abs(nums[ind] - nums[prev]) == 1) {
            take = 1 + solve(ind+1,ind,n,nums,dp);
        }

        nottake = solve(ind+1,prev,n,nums,dp);

        return dp[ind][prev + 1] = max(take, nottake);
    }
    int longestSubsequence(int N, int A[])
    {
       vector<vector<int>>dp(N,vector<int>(N,-1));
       return solve(0,-1,N,A,dp);
    }
};