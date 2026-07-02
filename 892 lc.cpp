class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int total_area = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];
                if (h > 0) {
                    total_area += 4 * h + 2;
                }
                
                // subtract overlapping faces with right neighbor
                if (j + 1 < n) {
                    total_area -= 2 * min(h, grid[i][j + 1]);
                }
                
                // subtract overlapping faces with bottom neighbor
                if (i + 1 < n) {
                    total_area -= 2 * min(h, grid[i + 1][j]);
                }
            }
        }
        
        return total_area;
    }
};
