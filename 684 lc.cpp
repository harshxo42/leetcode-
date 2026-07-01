#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; // They are already connected (cycle detected)
        }
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        vector<int> redundantEdge;
        
        for (const auto& edge : edges) {
            int u = edge[0] - 1; // Convert to 0-based indexing
            int v = edge[1] - 1;
            
            if (!uf.unionSets(u, v)) {
                // This edge creates a cycle
                redundantEdge = edge;
            }
        }
        
        return redundantEdge;
    }
};
