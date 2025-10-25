class Solution {
public:
    int solve(vector<int> &jd, int d, int ind, vector<vector<int>> &dp){
        if(d == 1){
            int maxi = INT_MIN;
            for(int i = ind; i < jd.size(); ++i){
                maxi = max(maxi, jd[i]);
            }

            return maxi;
        }
        if(dp[ind][d] != -1) return dp[ind][d];
        int maxi = jd[ind];
        int result = INT_MAX;
        for(int i = ind; i <= jd.size() - d; ++i){
            maxi = max(maxi, jd[i]);

            int total = maxi + solve(jd, d - 1, i + 1, dp);

            result = min(result, total);
        }
        return dp[ind][d] = result;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();

        if(n < d) return -1;

        vector<vector<int>> dp(n, vector<int> (d + 1, -1));
        return solve(jd, d, 0, dp);
    }
};