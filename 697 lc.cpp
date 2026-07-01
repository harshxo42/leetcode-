#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;
        
        // Store frequencies and first/last occurrence
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freq[num]++;
            if (first.find(num) == first.end()) {
                first[num] = i;
            }
            last[num] = i;
        }
        
        // Find the degree
        int degree = 0;
        for (auto& p : freq) {
            degree = max(degree, p.second);
        }
        
        // Find shortest subarray with same degree
        int minLen = nums.size();
        for (auto& p : freq) {
            if (p.second == degree) {
                int num = p.first;
                int len = last[num] - first[num] + 1;
                minLen = min(minLen, len);
            }
        }
        
        return minLen;
    }
};
