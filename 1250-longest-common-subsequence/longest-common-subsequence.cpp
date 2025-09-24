class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = m-1; i >= 0; --i){
            for(int j  = n-1; j >= 0; --j){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int solve(int mind, int nind, int m , int n, string text1, string text2,vector<vector<int>> &dp){
    if (mind == m || nind == n) {
        return dp[mind][nind] = 0;
    }

    if (text1[mind] == text2[nind]) {
        return dp[mind][nind] = 1 + solve(mind + 1,nind+1, m, n, text1, text2, dp);
    }

    return dp[mind][nind] = max(solve(mind + 1, nind, m, n, text1, text2, dp),
               solve(mind, nind + 1, m, n, text1, text2, dp));
    }
};


   