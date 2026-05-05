class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        
        for (int bit = 31; bit >= 0; bit--) {
            int mask = 1 << bit;
            
            // If this bit differs between left and right, stop
            if ((left & mask) != (right & mask)) {
                break;
            }
            
            // Otherwise, if it's set in left (and right), keep it in result
            if (left & mask) {
                result |= mask;
            }
        }
        
        return result;
    }
};
