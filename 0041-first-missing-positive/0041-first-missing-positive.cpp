#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Place each 1<=x<=n at location x-1
        for (int i = 0; i < n; ++i) {
            while (
                nums[i] >= 1 &&
                nums[i] <= n &&
                nums[i] != nums[nums[i] - 1]
            ) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Scan for the first missing integer
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        // If all 1...n present, return n+1
        return n + 1;
    }
};
