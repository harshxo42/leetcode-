class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        // dp[i][j] = length of longest palindromic subsequence in s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single character is always a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill dp table for substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // ending index
                
                if (s[i] == s[j]) {
                    // If characters match, add 2 to the inner subsequence
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // If they don't match, take the maximum of excluding one character
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
