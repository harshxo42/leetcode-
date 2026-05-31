#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort by end time
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        
        int keep = 1;  // first interval is always kept
        int lastEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEnd) {
                // No overlap, keep this interval
                keep++;
                lastEnd = intervals[i][1];
            }
            // Else overlap, skip (remove) this interval
        }
        
        return intervals.size() - keep;
    }
};
