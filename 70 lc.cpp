class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return climb(n, memo);
    }
    
private:
    int climb(int n, vector<int>& memo) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (memo[n] != -1) return memo[n];
        memo[n] = climb(n - 1, memo) + climb(n - 2, memo);
        return memo[n];
    }
};
