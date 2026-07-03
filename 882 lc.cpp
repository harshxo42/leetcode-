#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Build adjacency list with weight = cnt + 1
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            adj[u].push_back({v, cnt + 1});
            adj[v].push_back({u, cnt + 1});
        }
        
        // Dijkstra to find shortest distances from node 0
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Count reachable original nodes
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) result++;
        }
        
        // Count reachable new nodes on each edge
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int du = dist[u], dv = dist[v];
            
            // Nodes reachable from u side
            int from_u = max(0, min(cnt, maxMoves - du));
            // Nodes reachable from v side
            int from_v = max(0, min(cnt, maxMoves - dv));
            
            // Overlap: nodes reachable from both sides
            int left = max(1, cnt - (maxMoves - dv) + 1);
            int right = min(cnt, maxMoves - du);
            int overlap = 0;
            if (left <= right) overlap = right - left + 1;
            
            result += from_u + from_v - overlap;
        }
        
        return result;
    }
};
