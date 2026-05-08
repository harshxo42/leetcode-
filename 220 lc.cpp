#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> window;  // use long to avoid overflow when valueDiff is large
        
        for (int i = 0; i < nums.size(); i++) {
            // Find the smallest element >= nums[i] - valueDiff
            auto it = window.lower_bound((long)nums[i] - valueDiff);
            
            if (it != window.end() && *it <= (long)nums[i] + valueDiff) {
                return true;
            }
            
            window.insert(nums[i]);
            
            // Maintain window size ≤ indexDiff
            if (window.size() > indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        
        return false;
    }
};
