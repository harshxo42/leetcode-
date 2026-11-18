class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = INT_MIN, prefix = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            maxi = max(maxi, prefix);
            if(prefix < 0){
                prefix = 0;
            }
        }
        return maxi;   
    }
};