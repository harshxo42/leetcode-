#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, 
                                std::vector<std::vector<int>>& prerequisites) {
        // Build graph and in-degree array
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            graph[prerequisite].push_back(course);
            inDegree[course]++;
        }
        
        // Queue for BFS
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process courses
        std::vector<int> result;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            
            for (int dependent : graph[course]) {
                inDegree[dependent]--;
                if (inDegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }
        
        // Check if all courses can be taken
        if (result.size() == numCourses) {
            return result;
        }
        
        return {};
    }
};
