class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;  // Found a new lower buying price
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;  // Better profit if sell today
            }
        }
        
        return maxProfit;
    }
};
