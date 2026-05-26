#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // Map stone position to its index
        unordered_map<int, int> stoneIndex;
        for (int i = 0; i < n; i++) {
            stoneIndex[stones[i]] = i;
        }
        
        // dp[i] = set of jump lengths that can reach stone i
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);  // Start at stone 0 with last jump 0
        
        for (int i = 0; i < n; i++) {
            for (int k : dp[i]) {
                // Try jumps k-1, k, k+1
                for (int jump : {k - 1, k, k + 1}) {
                    if (jump <= 0) continue;
                    int nextPos = stones[i] + jump;
                    if (stoneIndex.count(nextPos)) {
                        int nextIndex = stoneIndex[nextPos];
                        dp[nextIndex].insert(jump);
                    }
                }
            }
        }
        
        return !dp[n - 1].empty();
    }
};
