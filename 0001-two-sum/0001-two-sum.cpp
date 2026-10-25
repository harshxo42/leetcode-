
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        vector<pair<int,int>> nums;

        for(int i = 0; i < arr.size(); i++) {
            nums.push_back({arr[i], i});
        }

        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {

            int sum = nums[start].first + nums[end].first;

            if(sum == target) {
                return {nums[start].second, nums[end].second};
            }
            else if(sum < target) {
                start++;
            }
            else {
                end--;
            }
        }

        return {};
    }
};
