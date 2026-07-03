#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        
        // dp[members][profit] = number of ways
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < group.size(); i++) {
            int g = group[i];
            int p = profit[i];
            
            // Iterate in reverse to avoid reusing the same crime
            for (int members = n; members >= g; members--) {
                for (int prof = minProfit; prof >= 0; prof--) {
                    int newProfit = min(minProfit, prof + p);
                    dp[members][newProfit] = (dp[members][newProfit] + dp[members - g][prof]) % MOD;
                }
            }
        }
        
        // Sum all ways where profit >= minProfit
        int result = 0;
        for (int members = 0; members <= n; members++) {
            result = (result + dp[members][minProfit]) % MOD;
        }
        return result;
    }
};
