class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) {
            return m * n;
        }
        
        int min_a = m;
        int min_b = n;
        
        for (const auto& op : ops) {
            min_a = min(min_a, op[0]);
            min_b = min(min_b, op[1]);
        }
        
        return min_a * min_b;
    }
};
