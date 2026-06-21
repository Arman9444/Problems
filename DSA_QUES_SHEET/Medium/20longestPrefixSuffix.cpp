//Knuth-Morris-Pratt (KMP) algorithm
class Solution {
public:
    int longestPrefixSuffix(string s) {
        int n = s.size();
        vector<int> lps(n, 0); // LPS array
        
        // Building the LPS array
        int len = 0; // Length of previous LPS
        int i = 1;   // Start from the second character
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Use the LPS value to skip mismatched characters
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Length of the longest prefix which is also a suffix
        int result = lps[n - 1];
        
        // Ensure it is not equal to the entire string length
        if (result == n) {
            result = lps[result - 1];
        }
        
        return result;
    }
};

// TLE but easy
class Solution {
public:
    int longestPrefixSuffix(string s) {
        int res = 0;
        int n = s.length();
        
        // Iterating over all possible lengths
        for (int len = 1; len < n; len++) {
            
            // Starting index of suffix
            int j = s.length() - len;
            
            bool flag = true;
            
            // Comparing proper prefix with suffix of length 'len'
            for (int k = 0; k < len; k++) {
                if (s[k] != s[j + k]) {  
                    flag = false;
                    break;
                }
            }
            
            // If they match, update the result
            if (flag)
                res = len;
        }
        
        return res;
    }
};