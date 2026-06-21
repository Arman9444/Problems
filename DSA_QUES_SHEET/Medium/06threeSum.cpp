// Editorial
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) { // i<nums.size() works too cause nothing happens in that case cause j becomes greater than k immediately
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return res;        
    }
};

// GPT
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate over the array
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // Target sum for the remaining two numbers
            int low = i + 1, high = n - 1;

            // Step 3: Two-pointer approach
            while (low < high) {
                int sum = nums[low] + nums[high];
                if (sum == target) {
                    result.push_back({nums[i], nums[low], nums[high]});

                    // Skip duplicate elements for the second number
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    // Skip duplicate elements for the third number
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                } else if (sum < target) {
                    low++; // Increase sum by moving the low pointer forward
                } else {
                    high--; // Decrease sum by moving the high pointer backward
                }
            }
        }

        return result;
    }
};
