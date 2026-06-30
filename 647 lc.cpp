#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        
        // Expand around center for each possible center
        for (int center = 0; center < n; center++) {
            // Odd length palindromes (single character center)
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            
            // Even length palindromes (between two characters center)
            left = center;
            right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};
