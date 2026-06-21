#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> createMatrix(int m, int n) {
        vector<vector<char>> matrix(m, vector<char>(n, ' '));
        char x = 'X'; // Start with 'X'

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Fill top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = x;
            }
            top++;

            // Fill right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = x;
            }
            right--;

            // Fill bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = x;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = x;
                }
                left++;
            }

            // Toggle between 'X' and 'O'
            x = (x == 'X') ? 'O' : 'X';
        }

        return matrix;
    }
};

int main() {
    int m = 6, n = 7;
    Solution sol;
    vector<vector<char>> matrix = sol.createMatrix(m, n);

    // Print the matrix
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
