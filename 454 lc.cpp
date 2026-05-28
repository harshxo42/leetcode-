#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, 
                     vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumCount;
        int n = nums1.size();
        
        // Step 1: store sums of pairs from nums1 and nums2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];
                sumCount[sum]++;
            }
        }
        
        // Step 2: count complements from nums3 and nums4
        int result = 0;
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                int sum = nums3[k] + nums4[l];
                result += sumCount[-sum];
            }
        }
        
        return result;
    }
};
