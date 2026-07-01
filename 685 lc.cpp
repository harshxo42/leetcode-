#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> inDegree(n + 1, 0);
        
        // Find nodes with two parents
        vector<int> candidate1, candidate2;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (inDegree[v] == 0) {
                inDegree[v] = u;
            } else {
                // v already has a parent, so this is a conflict
                candidate1 = {inDegree[v], v}; // first edge that points to v
                candidate2 = {u, v};           // second edge that points to v
                break;
            }
        }
        
        // If there's a node with two parents, try removing the second edge
        if (!candidate1.empty()) {
            // Check if removing candidate2 makes a valid tree
            if (isValidTree(edges, candidate2)) {
                return candidate2;
            } else {
                return candidate1;
            }
        }
        
        // No node with two parents => there must be a cycle
        // Use Union-Find to find the edge that creates the cycle
        return findCycleEdge(edges);
    }
    
private:
    bool isValidTree(const vector<vector<int>>& edges, const vector<int>& skipEdge) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        
        // Initialize parent for Union-Find
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        
        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return false;
            parent[rootX] = rootY;
            return true;
        };
        
        // Build the graph excluding the skipped edge
        for (const auto& edge : edges) {
            if (edge == skipEdge) continue;
            int u = edge[0], v = edge[1];
            if (!unionSets(u, v)) {
                return false; // Cycle detected
            }
        }
        
        // Count roots (nodes with no incoming edges in the constructed graph)
        vector<int> inDeg(n + 1, 0);
        for (const auto& edge : edges) {
            if (edge == skipEdge) continue;
            inDeg[edge[1]]++;
        }
        
        int rootCount = 0;
        for (int i = 1; i <= n; i++) {
            if (inDeg[i] == 0) rootCount++;
        }
        
        return rootCount == 1; // Must have exactly one root
    }
    
    vector<int> findCycleEdge(const vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        
        vector<int> cycleEdge;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) {
                cycleEdge = edge; // This edge creates a cycle
            } else {
                parent[rootU] = rootV;
            }
        }
        
        return cycleEdge;
    }
};
