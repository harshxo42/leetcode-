class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        
        for (int price : prices) {
            // First transaction: maximize profit after first buy/sell
            buy1 = max(buy1, -price);           // Best profit after first buy (negative of price)
            sell1 = max(sell1, buy1 + price);   // Best profit after first sell
            
            // Second transaction: use profit from first transaction
            buy2 = max(buy2, sell1 - price);    // Best profit after second buy (using profit from sell1)
            sell2 = max(sell2, buy2 + price);   // Best profit after second sell
        }
        
        return sell2;
    }
};
