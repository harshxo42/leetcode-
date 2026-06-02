#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        
        // Stack for potential '3' values
        std::stack<int> st;
        // 'third' will track the '2' value in the pattern
        int third = INT_MIN;
        
        // Scan from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If current number is less than third, we found a valid '1'
            if (nums[i] < third) {
                return true;
            }
            
            // While stack has values less than current number,
            // they become candidates for '2' (third)
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }
            
            // Push current number as potential '3'
            st.push(nums[i]);
        }
        
        return false;
    }
};
