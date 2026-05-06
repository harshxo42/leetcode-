#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // Build graph and calculate in-degrees
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            graph[prerequisite].push_back(course);  // prerequisite → course
            inDegree[course]++;
        }
        
        // Initialize queue with courses having no prerequisites
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process courses in topological order
        int completedCourses = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completedCourses++;
            
            // Remove this course and update dependencies
            for (int dependent : graph[course]) {
                inDegree[dependent]--;
                if (inDegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }
        
        // If we completed all courses, no cycle exists
        return completedCourses == numCourses;
    }
};
