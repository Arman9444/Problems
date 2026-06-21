// C++ Code to Merge Overlapping Intervals by checking 
// overlapping intervals only

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlap3(vector<vector<int>> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());
    vector<vector<int>> res;

    // Checking for all possible overlaps
    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        // Skipping already merged intervals
        if (!res.empty() && res.back()[1] >= end)
            continue;

        // Find the end of the merged range
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
        }
        res.push_back({start, end});
    }
    return res;
}

vector<vector<int>> mergeOverlap2(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
  
    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        vector<int>& last = res.back();
        vector<int>& curr = arr[i];

        // If current interval overlaps with the last merged
        // interval, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}

// Merge overlapping intervals in-place. We return
// modified size of the array arr.
int mergeOverlap(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());

    // Index of the last merged 
    int resIdx = 0; 

    for (int i = 1; i < arr.size(); i++) {
      
        // If current interval overlaps with the 
        // last merged interval
        if (arr[resIdx][1] >= arr[i][0])           
            arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);
      
        // Move to the next interval
        else {            
            resIdx++;
            arr[resIdx] = arr[i];
        }
    }

    // Returns size of the merged intervals
    return (resIdx + 1);
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    
    // Get the new size of the array after merging
    int newSize = mergeOverlap(arr);

    // Print the merged intervals based on the new size
    for (int i = 0; i < newSize; i++) {
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    return 0;
}