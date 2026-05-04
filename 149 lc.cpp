#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int maxPoints = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int samePoint = 1;
            int localMax = 0;
            
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                // Handle vertical/horizontal cases through gcd
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                // Make representation consistent: ensure dx non-negative
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                
                string slopeKey = to_string(dy) + "/" + to_string(dx);
                slopeCount[slopeKey]++;
                localMax = max(localMax, slopeCount[slopeKey]);
            }
            
            maxPoints = max(maxPoints, localMax + 1);
        }
        
        return maxPoints;
    }
    
private:
    int gcd(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};
