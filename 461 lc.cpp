class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorResult = x ^ y;  // Bits that are different become 1
        return __builtin_popcount(xorResult);  // Count the 1 bits
    }
};
