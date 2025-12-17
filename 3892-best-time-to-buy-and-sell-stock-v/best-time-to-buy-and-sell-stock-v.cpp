class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.resize(n + 1, vector<vector<long long>> (k + 1, vector<long long>(3, -1)));
       return solve(0, 0, prices, k);
    }

    long long solve(int ind, int status, vector<int> &prices, int k){
        if(k == 0) return 0;
        if(ind == prices.size()){
            if(status == 0) return 0;
            return INT_MIN;
        }
        if(dp[ind][k][status] != -1) return dp[ind][k][status];
        long long noPick = solve(ind + 1, status, prices, k);
        long long pick = 0;

        if(status == 1){
            pick = prices[ind] + solve(ind + 1, 0, prices, k - 1);
        }else if (status == 2){
            pick = -prices[ind] + solve(ind + 1, 0, prices, k - 1);
        }else{
            pick = max({pick, -prices[ind] + solve(ind + 1, 1, prices, k),
                    prices[ind] + solve(ind + 1, 2, prices, k)});
        }
        return  dp[ind][k][status] =max(pick, noPick);
    }
};