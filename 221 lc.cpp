class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> dp(n + 1, 0);
        int maxSide = 0;
        int prev = 0;  // stores dp[i-1][j-1]
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];  // save dp[j] before overwriting (it will be dp[i-1][j])
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    maxSide = max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;  // prev becomes dp[i-1][j-1] for next j
            }
            prev = 0;  // reset for next row
        }
        
        return maxSide * maxSide;
    }
};
