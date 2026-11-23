#include <vector>
using namespace std;

class Solution {
public:
    int findFirst(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
            if (nums[mid] == target) first = mid;
        }
        return first;
    }

    int findLast(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid - 1;
            if (nums[mid] == target) last = mid;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};
