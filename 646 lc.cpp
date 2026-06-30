#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by the second element (right endpoint)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 1;  // At least one pair can be used
        int currentEnd = pairs[0][1];  // End of the last selected pair
        
        // Greedily select the next pair with the smallest possible end
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > currentEnd) {
                // This pair can follow the current chain
                count++;
                currentEnd = pairs[i][1];
            }
        }
        
        return count;
    }
};
