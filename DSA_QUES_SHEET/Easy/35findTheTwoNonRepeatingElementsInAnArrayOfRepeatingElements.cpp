#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        int xorResult = 0;
        for (int num : arr) {
            xorResult ^= num; // XOR all numbers
        }

        // Find the rightmost set bit in xorResult
        int setBit = xorResult & ~(xorResult - 1);

        int num1 = 0, num2 = 0;

        // Separate numbers into two groups based on the setBit
        for (int num : arr) {
            if (num & setBit) {
                num1 ^= num; // Group 1
            } else {
                num2 ^= num; // Group 2
            }
        }

        // Return the two unique numbers in increasing order
        if (num1 > num2) swap(num1, num2);
        return {num1, num2};
    }
};
