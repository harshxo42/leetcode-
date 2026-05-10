#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        
        if (nums.empty()) {
            return result;
        }
        
        int start = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // If current number is not consecutive
            if (nums[i] > nums[i-1] + 1) {
                // End the previous range
                if (start == nums[i-1]) {
                    result.push_back(std::to_string(start));
                } else {
                    result.push_back(std::to_string(start) + "->" + std::to_string(nums[i-1]));
                }
                // Start a new range
                start = nums[i];
            }
        }
        
        // Handle the last range
        if (start == nums.back()) {
            result.push_back(std::to_string(start));
        } else {
            result.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
        }
        
        return result;
    }
};
