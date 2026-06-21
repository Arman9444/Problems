class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        int i=0;
        int n = arr.size();
        
        while(i < n) {
            if(arr[i] == x) {
                return i;
            }
            
            i += max(1, abs(arr[i]-x)/k);
        }
        
        return -1;
    }
};