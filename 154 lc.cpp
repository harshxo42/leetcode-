#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // min is in right half, exclude mid
                left = mid + 1;
            } 
            else if (nums[mid] < nums[right]) {
                // min is in left half including mid
                right = mid;
            } 
            else {
                // nums[mid] == nums[right]
                // cannot decide, shrink search space
                right--;
            }
        }
        
        return nums[left];
    }
};
