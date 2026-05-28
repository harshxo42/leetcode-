#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort by end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int arrowPos = points[0][1]; // Shoot first arrow at end of first balloon
        
        for (int i = 1; i < points.size(); i++) {
            // If this balloon starts after current arrow position
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1]; // Shoot new arrow at this balloon's end
            }
        }
        
        return arrows;
    }
};
