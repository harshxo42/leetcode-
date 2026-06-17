class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.length();
        int n = key.length();
        
        // Preprocess: store all positions of each character in ring
        vector<vector<int>> positions(26);
        for (int i = 0; i < m; i++) {
            positions[ring[i] - 'a'].push_back(i);
        }
        
        // dp[i][j] = minimum steps to spell key from index i 
        // when ring is currently at position j (aligned at 12:00)
        // Using 2D DP with memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // Recursive function with memoization
        function<int(int, int)> solve = [&](int keyIdx, int ringPos) -> int {
            // Base case: all characters spelled
            if (keyIdx == n) return 0;
            
            // Return cached result
            if (dp[keyIdx][ringPos] != -1) return dp[keyIdx][ringPos];
            
            char target = key[keyIdx];
            int minSteps = INT_MAX;
            
            // Try all positions where target character appears
            for (int targetPos : positions[target - 'a']) {
                // Calculate steps to rotate from ringPos to targetPos
                // Minimum of clockwise and counterclockwise rotations
                int clockwise = abs(ringPos - targetPos);
                int counterclockwise = m - clockwise;
                int rotateSteps = min(clockwise, counterclockwise);
                
                // 1 step to press the button + continue with next character
                int totalSteps = rotateSteps + 1 + solve(keyIdx + 1, targetPos);
                minSteps = min(minSteps, totalSteps);
            }
            
            return dp[keyIdx][ringPos] = minSteps;
        };
        
        // Start from first key character with ring at position 0
        return solve(0, 0);
    }
};
