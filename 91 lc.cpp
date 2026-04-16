#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Empty string
        dp[1] = 1;  // First character (already checked it's not '0')
        
        for (int i = 2; i <= n; i++) {
            // Check single digit (s[i-1])
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Check two digits (s[i-2]s[i-1])
            int twoDigits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};
