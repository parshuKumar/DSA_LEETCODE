class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int stsize = strs.size();
        vector<pair<int, int>> count;
        vector<vector<vector<int>>> dp(stsize + 1, vector<vector<int>>(m + 1, vector<int> (n + 1, -1)));
        for(int i = 0; i < strs.size(); ++i){
            int cnt0 = 0, cnt1 = 0;
            for(int j = 0; j < strs[i].size(); ++j){
                if(strs[i][j] == '0') cnt0++;
                else cnt1++;
            }
            count.push_back({cnt0, cnt1});
        }

        return solve(0, strs, m, n, count, dp);
    }

    int solve(int ind, vector<string> &strs, int m, int n, vector<pair<int, int>> &count, vector<vector<vector<int>>> &dp){
        if(m < 0 || n < 0) return -601;
        if(ind >= strs.size()) return 0;

        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        int pick = 1 + solve(ind + 1, strs, m - count[ind].first, n - count[ind].second, count, dp);
        int notPick = solve(ind + 1, strs, m , n, count, dp);

        return dp[ind][m][n] = max(pick, notPick);
    }
};