#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        std::unordered_set<std::string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) {
            return -1; // endGene not in bank, impossible
        }
        
        std::queue<std::pair<std::string, int>> q; // {gene, steps}
        std::unordered_set<std::string> visited;
        
        q.push({startGene, 0});
        visited.insert(startGene);
        
        char genes[] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            
            if (curr == endGene) {
                return steps;
            }
            
            // Try all possible mutations
            for (int i = 0; i < 8; i++) {
                char originalChar = curr[i];
                for (char g : genes) {
                    if (g == originalChar) continue; // skip same char
                    
                    curr[i] = g;
                    if (bankSet.find(curr) != bankSet.end() && visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        q.push({curr, steps + 1});
                    }
                }
                curr[i] = originalChar; // restore original
            }
        }
        
        return -1; // no valid path found
    }
};
