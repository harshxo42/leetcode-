class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        
        long long prev2 = 1; // dp[i-2]
        long long prev1 = 0; // dp[i-1]
        
        // Initialize for first character
        if (s[0] == '*') {
            prev1 = 9;
        } else if (s[0] >= '1' && s[0] <= '9') {
            prev1 = 1;
        } else {
            prev1 = 0;
        }
        
        if (n == 1) return prev1 % MOD;
        
        for (int i = 2; i <= n; i++) {
            char curr = s[i - 1];
            char prev = s[i - 2];
            long long currWays = 0;
            
            // Single digit decode
            if (curr == '*') {
                currWays = (currWays + prev1 * 9) % MOD;
            } else if (curr >= '1' && curr <= '9') {
                currWays = (currWays + prev1) % MOD;
            }
            
            // Two digit decode
            if (prev == '*') {
                if (curr == '*') {
                    currWays = (currWays + prev2 * 15) % MOD;
                } else if (curr >= '0' && curr <= '6') {
                    currWays = (currWays + prev2 * 2) % MOD;
                } else if (curr >= '7' && curr <= '9') {
                    currWays = (currWays + prev2 * 1) % MOD;
                }
            } else {
                if (curr == '*') {
                    if (prev == '1') {
                        currWays = (currWays + prev2 * 9) % MOD;
                    } else if (prev == '2') {
                        currWays = (currWays + prev2 * 6) % MOD;
                    }
                } else {
                    int twoDigit = (prev - '0') * 10 + (curr - '0');
                    if (twoDigit >= 10 && twoDigit <= 26) {
                        currWays = (currWays + prev2) % MOD;
                    }
                }
            }
            
            prev2 = prev1;
            prev1 = currWays;
        }
        
        return prev1 % MOD;
    }
};
