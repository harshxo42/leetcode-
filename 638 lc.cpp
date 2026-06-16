class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Remove offers that are more expensive than buying items individually
        vector<vector<int>> filteredSpecial;
        for (auto& offer : special) {
            int regularPrice = 0;
            for (int i = 0; i < price.size(); i++) {
                regularPrice += offer[i] * price[i];
            }
            if (offer.back() < regularPrice) {
                filteredSpecial.push_back(offer);
            }
        }
        
        // Memoization map: needs_state -> minimum cost
        unordered_map<string, int> memo;
        return dfs(price, filteredSpecial, needs, memo);
    }
    
private:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, 
            unordered_map<string, int>& memo) {
        // Create key for memoization
        string key = "";
        for (int need : needs) {
            key += to_string(need) + ",";
        }
        
        if (memo.count(key)) return memo[key];
        
        // Option 1: Buy all remaining items individually
        int minCost = 0;
        for (int i = 0; i < needs.size(); i++) {
            minCost += needs[i] * price[i];
        }
        
        // Option 2: Try each special offer
        for (auto& offer : special) {
            bool valid = true;
            vector<int> newNeeds = needs;
            
            // Check if we can apply this offer
            for (int i = 0; i < needs.size(); i++) {
                newNeeds[i] -= offer[i];
                if (newNeeds[i] < 0) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                int cost = offer.back() + dfs(price, special, newNeeds, memo);
                minCost = min(minCost, cost);
            }
        }
        
        memo[key] = minCost;
        return minCost;
    }
};
