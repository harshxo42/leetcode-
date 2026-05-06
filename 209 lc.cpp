#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLength = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            
            // Shrink window from left while condition is met
            while (currentSum >= target) {
                minLength = std::min(minLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        
        return minLength == INT_MAX ? 0 : minLength;
    }
};
