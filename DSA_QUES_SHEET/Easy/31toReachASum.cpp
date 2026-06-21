class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
        // Your code here
        vector<long long> dp(n + 1, 0);
        
        // Base case: one way to get a score of 0
        dp[0] = 1;
        
        // Iterate over each possible score increment (3, 5, 10)
        for (long long score : {3, 5, 10}) {
            for (long long i = score; i <= n; i++) {
                dp[i] += dp[i - score];
            }
        }
        
        return dp[n];
    }
};

// Editorial
class Solution {
public:
    // Complete this function
    long long solve(long long n, long long i,
                    vector<long long> v)
    {
        if (n == 0) {
            return 1;
        }

        if (i >= 3 || n < 0) {
            return 0;
        }

        long long take = solve(n - v[i], i, v);
        long long notTake = solve(n, i + 1, v);

        return (take + notTake);
    }

    long long int count(long long int n)
    {
        vector<long long> v = { 3, 5, 10 };
        return solve(n, 0, v);
    }
};

class Solution
{
    public:
    long long int count(long long int n)
    {
    	long long int table[n+1],i;
    	memset(table, 0, sizeof(table));
    	table[0]=1;                 // If 0 sum is required number of ways is 1.
    	for(i=3;i<=n;i++)
    		table[i]+=table[i-3];   // For every points (3,5,10) you need to add the number of ways to reach that sum 
    	for(i=5;i<=n;i++)           // before adding these points.
    		table[i]+=table[i-5];
    	for(i=10;i<=n;i++)
    		table[i]+=table[i-10];
    	return table[n];
    }
};