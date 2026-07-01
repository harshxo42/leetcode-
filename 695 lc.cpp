#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
        // Out of bounds or water or already visited
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
            return 0;
        }
        
        // Mark as visited by setting to 0
        grid[row][col] = 0;
        int area = 1; // count this cell
        
        // Explore all 4 directions
        for (auto& dir : directions) {
            area += dfs(grid, row + dir[0], col + dir[1]);
        }
        
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};
