class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, 
                   vector<vector<int>>& result) {
        // If current subsequence has at least 2 elements, add to result
        if (current.size() >= 2) {
            result.push_back(current);
        }
        
        // Use a set to avoid duplicates at the same level
        unordered_set<int> used;
        
        for (int i = start; i < nums.size(); i++) {
            // Skip if we've used this value before at this level
            if (used.find(nums[i]) != used.end()) {
                continue;
            }
            
            // Check if adding nums[i] maintains non-decreasing property
            if (current.empty() || nums[i] >= current.back()) {
                used.insert(nums[i]);
                current.push_back(nums[i]);
                backtrack(nums, i + 1, current, result);
                current.pop_back();  // backtrack
            }
        }
    }
};
