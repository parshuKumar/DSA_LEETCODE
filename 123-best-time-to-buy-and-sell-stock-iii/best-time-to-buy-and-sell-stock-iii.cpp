class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(2, -1)));
        return solve(0, prices, true, 0, dp); 
    }
    int solve(int start, vector<int>& prices, bool buy, int trans, vector<vector<vector<int>>> &dp) {
        if (start == prices.size() || trans == 2) {
            return 0;
        }
        if(dp[start][buy][trans] != -1) return dp[start][buy][trans];
        int profit = 0;

        if (buy) {
            int take = -prices[start] + solve(start + 1, prices, false, trans, dp);
            int notTake = 0 + solve(start + 1, prices, true, trans, dp);
            profit = max(take, notTake);
        } else {
            int sell =
                prices[start] + solve(start + 1, prices, true, trans + 1, dp);
            int notSell = 0 + solve(start + 1, prices, false, trans, dp);
            profit = max(sell, notSell);
        }

        return dp[start][buy][trans] = profit;
    }
};