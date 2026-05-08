#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        // Case 1: Rob houses from index 0 to n-2 (exclude last house)
        int case1 = linearRob(nums, 0, nums.size() - 2);
        
        // Case 2: Rob houses from index 1 to n-1 (exclude first house)
        int case2 = linearRob(nums, 1, nums.size() - 1);
        
        return max(case1, case2);
    }
    
private:
    int linearRob(vector<int>& nums, int start, int end) {
        int rob1 = 0;  // dp[i-2]
        int rob2 = 0;  // dp[i-1]
        
        for (int i = start; i <= end; i++) {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};
