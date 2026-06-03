#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        int W = std::sqrt(area);
        while (area % W != 0) {
            W--;
        }
        return {area / W, W};
    }
};
