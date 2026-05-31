#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        
        // Store (start, original_index) and sort by start
        std::vector<std::pair<int, int>> starts; // {start_value, original_index}
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        
        // Sort by start value (start is unique, but we sort anyway)
        std::sort(starts.begin(), starts.end());
        
        std::vector<int> result(n, -1);
        
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            
            // Binary search: find first start >= end
            int left = 0, right = n - 1;
            int idx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first >= end) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            if (idx != -1) {
                result[i] = starts[idx].second;
            }
        }
        
        return result;
    }
};
