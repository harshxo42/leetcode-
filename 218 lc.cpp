#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Step 1: Create events (x, height) where height is positive for start, negative for end
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.push_back({b[0], b[2]});  // start
            events.push_back({b[1], -b[2]}); // end
        }

        // Sort events by x, and for same x, start events first (higher height)
        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            // For same x: start events first (positive height comes first)
            return a.second > b.second;
        });

        // Max-heap to store active building heights
        priority_queue<int> heap;  // max-heap in C++
        // Hash map to track heights to be removed lazily
        map<int, int> toRemove;

        vector<vector<int>> result;
        int prevMax = 0;

        for (auto& e : events) {
            int x = e.first;
            int h = e.second;

            if (h > 0) {  // Start event
                heap.push(h);
            } else {  // End event
                toRemove[-h]++;  // Mark height to be removed later
            }

            // Remove heights from heap that are marked for removal
            while (!heap.empty() && toRemove[heap.top()] > 0) {
                toRemove[heap.top()]--;
                heap.pop();
            }

            int currentMax = heap.empty() ? 0 : heap.top();

            // If height changed, record key point
            if (currentMax != prevMax) {
                result.push_back({x, currentMax});
                prevMax = currentMax;
            }
        }

        return result;
    }
};
