class Solution {
public:
    int transform(string A, string B) {
        if (A.length() != B.length()) return -1;

        int n = A.length();
        vector<int> count(256, 0);

        // Count character frequencies for both strings
        for (char c : A) count[c]++;
        for (char c : B) count[c]--;
        
        // Check if transformation is possible
        for (int c : count) {
            if (c != 0) return -1;
        }

        // Find the longest matching suffix
        int i = n - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] == B[j]) {
                j--; // Match found, move to next character in B
            }
            i--; // Always move in A
        }

        // Return the minimum number of operations
        return j + 1;
    }
};
