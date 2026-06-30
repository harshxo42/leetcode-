#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int duplicate = -1;
        
        // Find the duplicate
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                duplicate = num;
            } else {
                seen.insert(num);
            }
        }
        
        // Find the missing number
        for (int i = 1; i <= n; i++) {
            if (seen.find(i) == seen.end()) {
                return {duplicate, i};
            }
        }
        
        return {duplicate, -1}; // Should never reach here
    }
};
