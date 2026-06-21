class Solution {
  public:
    int findMinDiff(vector<int>& arr, int m) {
        vector<int> diff;
        
        sort(arr.begin(), arr.end());
        
        for(int i=m-1; i<arr.size(); i++) {
            int dif = arr[i] - arr[i-m+1];
            
            diff.push_back(dif);
        }
        
        sort(diff.begin(), diff.end());
        
        int max_diff = INT_MAX;
        
        for(int i=0; i<diff.size(); i++) {
            max_diff = min(max_diff, diff[i]);
        }
        
        return max_diff;
    }
};