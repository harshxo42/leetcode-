#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            
            // Temporary variables because maxProd gets updated before minProd calculation
            int tempMax = max({curr, maxProd * curr, minProd * curr});
            int tempMin = min({curr, maxProd * curr, minProd * curr});
            
            maxProd = tempMax;
            minProd = tempMin;
            
            result = max(result, maxProd);
        }
        
        return result;
    }
};
