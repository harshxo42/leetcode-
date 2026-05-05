class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        transform(nums.begin(), nums.end(), back_inserter(strs), 
                  [](int num) { return to_string(num); });
        
        sort(strs.begin(), strs.end(), 
             [](const string& a, const string& b) { return a + b > b + a; });
        
        return strs[0] == "0" ? "0" : accumulate(strs.begin(), strs.end(), string(""));
    }
};
