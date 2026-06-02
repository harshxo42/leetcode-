#include <vector>
#include <cmath>

class Solution {
public:
    bool circularArrayLoop(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> visited(n, 0); // 0=unvisited, 1=visiting, 2=processed
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (dfs(nums, visited, i, nums[i] > 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(std::vector<int>& nums, std::vector<int>& visited, int start, bool isForward) {
        int n = nums.size();
        int slow = start;
        int fast = start;
        
        // Check if starting node's direction matches
        if ((nums[start] > 0) != isForward) {
            return false;
        }
        
        while (true) {
            // Move slow one step
            slow = getNext(nums, slow);
            if ((nums[slow] > 0) != isForward) {
                return false;
            }
            
            // Move fast two steps
            fast = getNext(nums, fast);
            if ((nums[fast] > 0) != isForward) {
                return false;
            }
            fast = getNext(nums, fast);
            if ((nums[fast] > 0) != isForward) {
                return false;
            }
            
            // Check if we found a cycle
            if (slow == fast) {
                // Verify cycle length > 1
                int cycleLength = 1;
                int curr = getNext(nums, slow);
                while (curr != slow) {
                    cycleLength++;
                    curr = getNext(nums, curr);
                }
                return cycleLength > 1;
            }
        }
    }
    
    int getNext(std::vector<int>& nums, int i) {
        int n = nums.size();
        int next = i + nums[i];
        next %= n;
        if (next < 0) next += n;
        return next;
    }
};
