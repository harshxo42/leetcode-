#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& comb, int idx) {
        if (target == 0) {
            result.push_back(comb);
            return;
        }
        if (target < 0) return;
        for (int i = idx; i < candidates.size(); ++i) {
            comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, comb, i);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        backtrack(candidates, target, result, comb, 0);
        return result;
    }
};

