class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        
        for (int house : houses) {
            // Find the closest heater to this house
            int closest = findClosestHeater(heaters, house);
            radius = max(radius, closest);
        }
        
        return radius;
    }
    
private:
    int findClosestHeater(vector<int>& heaters, int house) {
        int left = 0, right = heaters.size() - 1;
        int minDist = INT_MAX;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            minDist = min(minDist, abs(heaters[mid] - house));
            
            if (heaters[mid] < house) {
                left = mid + 1;
            } else if (heaters[mid] > house) {
                right = mid - 1;
            } else {
                return 0; // exact match
            }
        }
        
        return minDist;
    }
};
