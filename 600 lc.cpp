class Solution {
public:
    int findIntegers(int n) {
        // Get bits of n
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n % 2);
            n /= 2;
        }
        reverse(bits.begin(), bits.end());
        int len = bits.size();
        
        // memo[pos][tight][prev]
        // pos: current index in bits array (from 0 to len-1)
        // tight: 0/1
        // prev: 0/1
        vector<vector<vector<int>>> memo(len, vector<vector<int>>(2, vector<int>(2, -1)));
        
        function<int(int, int, int)> dfs = [&](int pos, int tight, int prev) -> int {
            if (pos == len) {
                return 1; // successfully built a number
            }
            
            if (memo[pos][tight][prev] != -1) {
                return memo[pos][tight][prev];
            }
            
            int maxBit = tight ? bits[pos] : 1;
            int total = 0;
            
            for (int bit = 0; bit <= maxBit; bit++) {
                if (prev == 1 && bit == 1) {
                    continue; // can't have consecutive ones
                }
                total += dfs(pos + 1, tight && (bit == maxBit), bit);
            }
            
            return memo[pos][tight][prev] = total;
        };
        
        return dfs(0, 1, 0);
    }
};
