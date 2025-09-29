class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        dp[n] = 0;
        for(int i = n-1; i >=  0; --i){
            int pick1 = costs[i] + 1 + dp[i + 1];
            int pick2 = i + 1 < n ? costs[i + 1] + 4 + dp[i + 2] : INT_MAX;
            int pick3 = i + 2 < n ? costs[i + 2] + 9 + dp[i + 3] : INT_MAX;

            dp[i] = min({pick1, pick2, pick3});
        }
        return dp[0];

    }

    int solve(int ind, vector<int> &costs, vector<int> &dp){
        int n = costs.size();
        if(ind >= n){
            return 0;
        }
       if(dp[ind] != -1) return dp[ind];
       //pick
       int pick1 = costs[ind] + 1 + solve(ind + 1, costs, dp);
       int pick2 = ind + 1 < n ? costs[ind + 1] + 4 + solve(ind + 2, costs, dp) : 1e9;
       int pick3 = ind + 2 < n ? costs[ind + 2] + 9 + solve(ind + 3, costs, dp) : 1e9;

        return dp[ind] = min({pick1, pick2, pick3});
    }
};