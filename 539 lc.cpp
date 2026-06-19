#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert all times to minutes
        vector<int> minutes;
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the times
        sort(minutes.begin(), minutes.end());
        
        // Find minimum difference between consecutive times
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Check circular difference (between last and first + 24 hours)
        int circularDiff = (minutes[0] + 1440) - minutes.back();
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};
