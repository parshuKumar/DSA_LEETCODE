class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return solve(0, 0, text1, text2);
    }

    int solve(int i, int j, string &text1, string &text2){
        if(i == text1.size() || j == text2.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int length = 0;
        if(text1[i] == text2[j]){
            length =  1 + solve(i + 1, j + 1, text1, text2);
        }else{
            length =  max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));
        }

        return dp[i][j] = length;
    }
};