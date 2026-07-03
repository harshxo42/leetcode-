#include <string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long total_length = 0;
        
        // Step 1: Compute total length
        for (char c : s) {
            if (isalpha(c)) {
                total_length++;
            } else {
                total_length *= (c - '0');
            }
        }
        
        // Step 2: Traverse backwards to find the k-th character
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            
            if (isdigit(c)) {
                int digit = c - '0';
                total_length /= digit;
                k %= total_length;
                if (k == 0) {
                    k = total_length;
                }
            } else {
                // It's a letter
                if (k == total_length) {
                    return string(1, c);
                }
                total_length--;
            }
        }
        
        return ""; // Should never reach here
    }
};
