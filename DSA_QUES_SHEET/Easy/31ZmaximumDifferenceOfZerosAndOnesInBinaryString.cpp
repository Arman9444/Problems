class Solution {
  public:
    int maxSubstring(string S) {
        int max_sum = INT_MIN, current_sum = 0;
        
        for (char ch : S) {
            int value = (ch == '0') ? 1 : -1;
            current_sum += value;
            
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        
        // If max_sum is still negative, it means the string contains only 1s
        return (max_sum > 0) ? max_sum : -1;
    }
};