#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        return sum - (long long)minVal * nums.size();
    }
};
