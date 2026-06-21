#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        // Array to store column indices for each row
        vector<int> columnIndices(n, m - 1);

        while (true) {
            int minRow = 0;
            int maxElement = mat[0][columnIndices[0]];

            // Find the row with the minimum element
            for (int i = 1; i < n; i++) {
                if (mat[i][columnIndices[i]] < mat[minRow][columnIndices[minRow]]) {
                    minRow = i;
                }
                maxElement = max(maxElement, mat[i][columnIndices[i]]);
            }

            // Check if all elements in the last column indices are the same
            int minElement = mat[minRow][columnIndices[minRow]];
            int count = 0;

            for (int i = 0; i < n; i++) {
                if (mat[i][columnIndices[i]] == minElement) {
                    count++;
                } else {
                    break;
                }
            }

            if (count == n) {
                return minElement; // Found the common element
            }

            // Reduce the column index of rows whose element is smaller than the maximum
            for (int i = 0; i < n; i++) {
                if (mat[i][columnIndices[i]] < maxElement) {
                    columnIndices[i]--;
                    if (columnIndices[i] < 0) {
                        return -1; // No common element
                    }
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4, 5},
        {2, 4, 5, 8, 10},
        {3, 5, 7, 9, 11},
        {1, 3, 5, 7, 9}
    };

    Solution sol;
    int commonElement = sol.findCommonElement(mat);
    if (commonElement != -1) {
        cout << "Common Element: " << commonElement << endl;
    } else {
        cout << "No Common Element Found" << endl;
    }
    return 0;
}
