class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        for (int stick : matchsticks) total += stick;
        
        if (total % 4 != 0) return false;
        
        int sideLength = total / 4;
        
        // Sort in descending order for pruning
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        int n = matchsticks.size();
        // Memoization: dp[mask] = current sum for current side being filled
        unordered_map<int, int> memo;
        
        return dfs(matchsticks, 0, 0, sideLength, 0, memo);
    }
    
private:
    bool dfs(vector<int>& matchsticks, int mask, int currentSum, 
             int target, int sidesCompleted, 
             unordered_map<int, int>& memo) {
        
        if (sidesCompleted == 3) return true; // Last side must be complete
        
        if (currentSum == target) {
            // Current side completed, start next side
            return dfs(matchsticks, mask, 0, target, sidesCompleted + 1, memo);
        }
        
        if (memo.count(mask)) return false;
        
        int n = matchsticks.size();
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)) && currentSum + matchsticks[i] <= target) {
                if (dfs(matchsticks, mask | (1 << i), 
                       currentSum + matchsticks[i], target, 
                       sidesCompleted, memo)) {
                    return true;
                }
            }
        }
        
        memo[mask] = 0;
        return false;
    }
};
