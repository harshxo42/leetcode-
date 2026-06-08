class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (const string& s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.length() - zeros;
            
            // Iterate backwards to avoid using same string multiple times
            for (int z = m; z >= zeros; z--) {
                for (int o = n; o >= ones; o--) {
                    dp[z][o] = max(dp[z][o], dp[z - zeros][o - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
