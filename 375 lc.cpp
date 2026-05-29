#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j] = minimum money needed to guarantee win for range [i..j]
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
        
        // length of the range
        for (int length = 2; length <= n; length++) {
            for (int i = 1; i + length - 1 <= n; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                
                // try each guess x in [i..j]
                for (int x = i; x <= j; x++) {
                    int cost = x + std::max(dp[i][x - 1], dp[x + 1][j]);
                    dp[i][j] = std::min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][n];
    }
};
