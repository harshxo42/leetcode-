class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());  // sort to handle duplicates
        backtrack(nums, used, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, used, path, res);

            path.pop_back();
            used[i] = false;
        }
    }
};
