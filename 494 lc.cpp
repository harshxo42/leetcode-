class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If target is out of range or (totalSum + target) is odd
        if (target > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }
        
        int subsetSum = (totalSum + target) / 2;
        int n = nums.size();
        
        // dp[i][j] = ways to get sum j using first i elements
        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));
        
        // Base case: sum 0 can be achieved with 0 elements in 1 way
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= subsetSum; j++) {
                // Don't take nums[i-1]
                dp[i][j] = dp[i - 1][j];
                
                // Take nums[i-1] if possible
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[n][subsetSum];
    }
};
