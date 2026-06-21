class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_set<char> set;
        int n = str.size(), left = 0, max_length = 0;

        for(int right = 0; right<n; right++) {
            if(set.count(str[right]) == 0) {
                set.insert(str[right]);
                max_length = max(max_length, right-left+1);
            } else {
                while(set.count(str[right])) {
                    set.erase(str[left]);
                    left++;
                }
                set.insert(str[right]);
            }
        }

        return max_length;
    }
};