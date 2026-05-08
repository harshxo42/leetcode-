#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Create combined string: s + "#" + rev
        string combined = s + "#" + rev;
        
        // Build LPS array for combined string
        int n = combined.length();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // Length of longest palindromic prefix
        int len = lps[n - 1];
        
        // Remaining suffix to prepend (reversed)
        string toAdd = s.substr(len);
        reverse(toAdd.begin(), toAdd.end());
        
        return toAdd + s;
    }
};
