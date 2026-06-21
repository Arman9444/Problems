#include <iostream>
#include <string>
using namespace std;

// Function to expand around the center and return the length of the palindrome
int expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}

// Function to find the longest palindromic substring
string longestPalindrome(const string& s) {
    if (s.empty()) return "";
    
    int start = 0, maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        // Check for odd-length palindromes
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindromes
        int len2 = expandAroundCenter(s, i, i + 1);
        // Find the maximum length
        int len = max(len1, len2);

        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2; // Calculate the starting index
        }
    }

    return s.substr(start, maxLength);
}

// Main function to test the code
int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "The longest palindromic substring is: " << result << endl;

    return 0;
}
