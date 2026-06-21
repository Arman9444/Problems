#include <iostream>
#include <string>
using namespace std;

// Function to expand around the center and count palindromic substrings
int expandAroundCenter(const string& s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        count++; // Increment count for each palindrome found
        left--;
        right++;
    }
    return count;
}

// Function to count the number of palindromic substrings
int countSubstrings(const string& s) {
    int totalCount = 0;

    for (int i = 0; i < s.size(); i++) {
        // Count odd-length palindromes (single character center)
        totalCount += expandAroundCenter(s, i, i);
        // Count even-length palindromes (two-character center)
        totalCount += expandAroundCenter(s, i, i + 1);
    }

    return totalCount;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = countSubstrings(s);
    cout << "The number of palindromic substrings is: " << result << endl;

    return 0;
}
