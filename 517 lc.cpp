class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        long long total = 0;
        
        // Calculate total dresses
        for (int dresses : machines) {
            total += dresses;
        }
        
        // If total is not divisible by n, impossible
        if (total % n != 0) {
            return -1;
        }
        
        int target = total / n;
        int answer = 0;
        int cumulative = 0;
        
        for (int dresses : machines) {
            // Each machine's surplus/deficit
            int diff = dresses - target;
            
            // Cumulative load that needs to pass through this point
            cumulative += diff;
            
            // Answer is max of:
            // 1. Maximum absolute cumulative load (dresses passing through)
            // 2. Maximum absolute diff (dresses a single machine needs to handle)
            answer = max({answer, abs(cumulative), abs(diff)});
        }
        
        return answer;
    }
};
