class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size();
        int ans = INT_MIN; // Initialize the maximum product as the smallest possible integer
        int l = 0, r = 0;  // Variables to store the running product from the left and right

        // Iterate through the array to calculate maximum product in both directions
        for (int i = 0; i < n; i++) {
            // Calculate the left running product
            // If `l` becomes zero due to a zero in the array, reset it to 1
            l = (l ? l : 1) * A[i];
            
            // Calculate the right running product
            // If `r` becomes zero due to a zero in the array, reset it to 1
            r = (r ? r : 1) * A[n - 1 - i];
            
            // Update the maximum product by considering both left and right products
            ans = max(ans, max(l, r));
        }
        
        return ans; // Return the maximum product found
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0]; // Maximum product overall
        int curMax = nums[0];  // Maximum product ending at current position
        int curMin = nums[0];  // Minimum product ending at current position

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(curMax, curMin); // Swap when the current number is negative
            }

            curMax = max(nums[i], curMax * nums[i]); // Update current max
            curMin = min(nums[i], curMin * nums[i]); // Update current min

            maxProd = max(maxProd, curMax); // Update the overall max product
        }

        return maxProd;
    }
};