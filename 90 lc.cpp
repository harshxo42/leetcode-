#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        
        backtrack(nums, 0, current, result);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, 
                   vector<int>& current, 
                   vector<vector<int>>& result) {
        // Add the current subset to result
        result.push_back(current);
        
        // Try adding each remaining element
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates: if same as previous element and not first in this level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include nums[i]
            current.push_back(nums[i]);
            
            // Recurse with next starting index
            backtrack(nums, i + 1, current, result);
            
            // Backtrack: remove nums[i]
            current.pop_back();
        }
    }
};
