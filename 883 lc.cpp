#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int top = 0, front = 0, side = 0;
        
        // Compute top view and row/column maximums
        for (int i = 0; i < n; i++) {
            int row_max = 0;
            int col_max = 0;
            for (int j = 0; j < n; j++) {
                // Top view: any non-zero cell contributes 1
                if (grid[i][j] > 0) top++;
                
                // Row maximum for side view
                row_max = max(row_max, grid[i][j]);
                
                // Column maximum for front view
                col_max = max(col_max, grid[j][i]);
            }
            side += row_max;
            front += col_max;
        }
        
        return top + front + side;
    }
};
