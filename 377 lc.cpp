class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int t = 1; t <= target; t++) {
            for (int x : nums) {
                if (t >= x) {
                    dp[t] += dp[t - x];
                }
            }
        }
        
        return dp[target];
    }
};
