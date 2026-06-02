#include <string>
#include <vector>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        int n = s.length();
        
        // Build LPS array (Longest Proper Prefix which is also Suffix)
        std::vector<int> lps(n, 0);
        int len = 0; // length of previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Check if the string can be divided into repeated pattern
        int lpsValue = lps[n - 1];
        return lpsValue > 0 && (n % (n - lpsValue) == 0);
    }
};
