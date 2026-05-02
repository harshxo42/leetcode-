class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Precompute palindrome table
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        
        // All single chars are palindromes
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        
        // Length 2 palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                isPalin[i][i+1] = true;
            }
        }
        
        // Length >= 3 palindromes
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPalin[i+1][j-1]) {
                    isPalin[i][j] = true;
                }
            }
        }
        
        // DP for min cuts
        vector<int> dp(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i]) {
                dp[i] = 0;
                continue;
            }
            
            for (int j = 0; j < i; j++) {
                if (isPalin[j+1][i]) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return dp[n-1];
    }
};
