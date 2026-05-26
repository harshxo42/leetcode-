#include <cmath>

class Solution {
public:
    int findNthDigit(int n) {
        // Step 1: Find which group (digit length) contains the nth digit
        long long digitLen = 1;
        long long count = 9;
        
        while (n > digitLen * count) {
            n -= digitLen * count;
            digitLen++;
            count *= 10;
        }
        
        // Step 2: Find the actual number
        long long startNumber = pow(10, digitLen - 1);
        long long offset = (n - 1) / digitLen;
        long long actualNumber = startNumber + offset;
        
        // Step 3: Find which digit within that number
        int digitPos = (n - 1) % digitLen;
        
        // Step 4: Extract the digit
        string numStr = to_string(actualNumber);
        return numStr[digitPos] - '0';
    }
};
