class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1, ans = 0;

        while(start < end) {
            int width = end-start;

            int currWater = min(height[start], height[end]) * width;

            ans = max(ans, currWater);

            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }

        return ans;
    }
};