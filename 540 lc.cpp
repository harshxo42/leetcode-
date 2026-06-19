class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is even or odd
            if (mid % 2 == 1) {
                mid--; // Make mid even for easier comparison
            }
            
            // If the pair (mid, mid+1) is valid, the single element is on the right
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                // Otherwise, the single element is on the left
                right = mid;
            }
        }
        
        return nums[left];
    }
};
