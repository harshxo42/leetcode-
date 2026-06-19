#include <string>
#include <algorithm>

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            // Determine the end of the segment to reverse
            // We reverse from i to min(i + k, n) - 1
            int end = min(i + k, n);
            reverse(s.begin() + i, s.begin() + end);
        }
        
        return s;
    }
};
