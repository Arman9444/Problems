//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string smallestWindow(string &s1, string &s2) {
        if (s2.size() > s1.size()) return ""; // Impossible case

        // Frequency map for characters in s2
        unordered_map<char, int> freqS2;
        for (char c : s2) freqS2[c]++;
        
        // Variables to track the sliding window
        int left = 0, minLength = INT_MAX, start = -1, matchCount = 0;
        unordered_map<char, int> windowFreq;

        // Traverse s1 using the right pointer
        for (int right = 0; right < s1.size(); right++) {
            char c = s1[right];
            windowFreq[c]++;
            
            // Check if character contributes to a valid match
            if (freqS2.find(c) != freqS2.end() && windowFreq[c] <= freqS2[c]) {
                matchCount++;
            }

            // If all characters of s2 are matched
            while (matchCount == s2.size()) {
                // Update the smallest window
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                
                // Shrink the window from the left
                char leftChar = s1[left];
                windowFreq[leftChar]--;
                if (freqS2.find(leftChar) != freqS2.end() && windowFreq[leftChar] < freqS2[leftChar]) {
                    matchCount--;
                }
                left++;
            }
        }

        // Return the smallest window or an empty string if no valid window exists
        return start == -1 ? "" : s1.substr(start, minLength);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends