class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // stores indices
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices from back while their values are <= current value
            // (they can't be the max for future windows)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // Add current index
            dq.push_back(i);
            
            // Remove indices that are out of the current window
            // Window is [i - k + 1, i]
            if (dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // If we have a complete window, the front is the maximum
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};
