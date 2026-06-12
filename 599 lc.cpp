class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> result;
        int minSum = INT_MAX;
        
        // Store all strings from list1 with their indices
        for (int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }
        
        // Check each string in list2
        for (int j = 0; j < list2.size(); j++) {
            // If this string exists in list1
            if (map.find(list2[j]) != map.end()) {
                int i = map[list2[j]];
                int sum = i + j;
                
                // If we found a smaller sum, clear result and update minSum
                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                }
                // If we found same sum, add to result
                else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        
        return result;
    }
};
