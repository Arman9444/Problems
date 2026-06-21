class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Compute prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix; // Store the product of elements to the left
            prefix *= nums[i];
        }

        // Compute suffix products and multiply with the prefix
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix; // Multiply with the product of elements to the right
            suffix *= nums[i];
        }

        return ans;
    }
};
