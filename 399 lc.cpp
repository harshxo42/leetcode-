#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        // Build graph: variable -> list of (neighbor, value)
        unordered_map<string, vector<pair<string, double>>> graph;
        
        // Add edges for each equation
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }
        
        // Process each query
        vector<double> results;
        for (auto& query : queries) {
            string C = query[0];
            string D = query[1];
            
            // If variables don't exist in graph
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
                continue;
            }
            
            // If same variable
            if (C == D) {
                results.push_back(1.0);
                continue;
            }
            
            // BFS to find path from C to D
            queue<pair<string, double>> q;
            unordered_set<string> visited;
            
            q.push({C, 1.0});
            visited.insert(C);
            
            double answer = -1.0;
            
            while (!q.empty()) {
                auto [current, product] = q.front();
                q.pop();
                
                for (auto& [neighbor, weight] : graph[current]) {
                    if (neighbor == D) {
                        answer = product * weight;
                        break;
                    }
                    
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push({neighbor, product * weight});
                    }
                }
                
                if (answer != -1.0) break;
            }
            
            results.push_back(answer);
        }
        
        return results;
    }
};
