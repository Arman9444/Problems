#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0); // Frequency of characters
        int maxFreq = 0;        // Max frequency of any character in the window
        int left = 0;           // Left pointer of the sliding window
        int maxLength = 0;      // Maximum length of valid substring

        for (int right = 0; right < n; ++right) {
            // Update the frequency of the current character
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']); // Update max frequency

            // Check if the window is valid
            if ((right - left + 1) - maxFreq > k) {
                // Shrink the window from the left
                freq[s[left] - 'A']--;
                left++;
            }

            // Update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Example 1: " << solution.characterReplacement(s1, k1) << endl;

    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Example 2: " << solution.characterReplacement(s2, k2) << endl;

    return 0;
}
