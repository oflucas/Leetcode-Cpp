class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        
        if (k > n / 2) {
            int res = 0;
            for (int i = 1; i < n; i++)
                res += max(prices[i] - prices[i - 1], 0);
            return res;
        }
        
        int profit[k + 1][n];
        memset(profit, 0 , sizeof profit);
        for (int i = 1; i <= k; i++) {
            int bestBuy = -prices[0];
            for (int j = 1; j < n; j++) {
                profit[i][j] = max(profit[i][j - 1], bestBuy + prices[j]);
                bestBuy = max(bestBuy, profit[i - 1][j] - prices[j]);
            }
        }
        return profit[k][n - 1];
    }
};
