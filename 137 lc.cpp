#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (int num : nums) {
                // Check if the i-th bit is set in num
                if ((num >> i) & 1) {
                    bitSum++;
                }
            }
            // If count of 1's mod 3 is 1, then set this bit in result
            if (bitSum % 3 == 1) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};
