#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize: add all 0 cells to queue with distance 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for (auto [dr, dc] : dirs) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                // Check bounds and if we can improve the distance
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (dist[newRow][newCol] > dist[row][col] + 1) {
                        dist[newRow][newCol] = dist[row][col] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return dist;
    }
};
