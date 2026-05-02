class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int startIndex = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            
            tank += gas[i] - cost[i];
            
            // If tank goes negative, can't start from current startIndex
            if (tank < 0) {
                // Start from next station
                startIndex = i + 1;
                tank = 0;
            }
        }
        
        // If total gas >= total cost, solution exists at startIndex
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};
