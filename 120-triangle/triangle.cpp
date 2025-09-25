class Solution {
public:
    // int solveDP(vector<vector<int>> tri, int start, int ind, int n,
    // vector<vector<int>> &dp){
    //     if(start == n-1){
    //         return dp[start][ind] = tri[start][ind];
    //     }
    //     if(dp[start][ind] != -1) return dp[start][ind];
    //     int a = tri[start][ind] + solveDP(tri, start+1, ind, n, dp );
    //     int b = tri[start][ind] + solveDP(tri, start + 1, ind + 1, n, dp);

    //     return dp[start][ind] = min(a, b);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveDP(triangle, 0,0, n, dp);

        for (int i = n - 1; i >= 0; i--) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i; j >= 0; --j) {
                int a = triangle[i][j] + dp[i + 1][j];
                int b = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(a, b);
            }
        }
        return dp[0][0];
    }
};