#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        int n = g.size(), m = s.size();
        
        while (i < n && j < m) {
            if (s[j] >= g[i]) {
                i++; // child content, move to next child
            }
            j++; // move to next cookie (whether assigned or not)
        }
        
        return i;
    }
};
