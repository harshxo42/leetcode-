#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // Key idea: Use a map to track the parity of corner points
        unordered_map<long long, int> cornerCount;
        
        long long totalArea = 0;
        int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
        
        auto hashPoint = [](int x, int y) -> long long {
            return (static_cast<long long>(x) << 32) ^ y;
        };
        
        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            
            // Update bounding rectangle
            xmin = min(xmin, x1);
            ymin = min(ymin, y1);
            xmax = max(xmax, x2);
            ymax = max(ymax, y2);
            
            // Add area
            totalArea += static_cast<long long>(x2 - x1) * (y2 - y1);
            
            // Add corners to map with parity (XOR behavior)
            cornerCount[hashPoint(x1, y1)]++;
            cornerCount[hashPoint(x2, y1)]++;
            cornerCount[hashPoint(x1, y2)]++;
            cornerCount[hashPoint(x2, y2)]++;
        }
        
        // Check area condition
        long long boundingArea = static_cast<long long>(xmax - xmin) * (ymax - ymin);
        if (totalArea != boundingArea) return false;
        
        // Check corner points parity
        // Collect points with odd counts
        vector<pair<int, int>> oddPoints;
        for (const auto& [hash, count] : cornerCount) {
            if (count % 2 == 1) {
                int x = hash >> 32;
                int y = static_cast<int>(hash);
                oddPoints.push_back({x, y});
            }
        }
        
        // We should have exactly 4 odd points and they should be the 4 corners
        if (oddPoints.size() != 4) return false;
        
        // Check if these 4 points are exactly the bounding rectangle's corners
        // Sort to compare with expected corners
        vector<pair<int, int>> expected = {
            {xmin, ymin}, {xmax, ymin}, {xmin, ymax}, {xmax, ymax}
        };
        sort(oddPoints.begin(), oddPoints.end());
        sort(expected.begin(), expected.end());
        
        return oddPoints == expected;
    }
};
