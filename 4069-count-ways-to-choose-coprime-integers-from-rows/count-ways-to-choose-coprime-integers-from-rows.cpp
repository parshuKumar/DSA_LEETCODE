class Solution {
public:
    const int mod = 1e9 + 7;
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int> (151, -1));
        
        int result =  solve(0, 0, n, mat, dp);

        // for(auto a : dp){
        //     for(int c : a){
        //         cout << c << " ";
        //     }
        //     cout << endl;
        // }

        return dp[0][0];
    }

    int solve(int row,int g, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(row == n){
            return g == 1;
        }

        if(dp[row][g] != -1) return dp[row][g];
        int ans = 0;

        for(int j = 0; j < mat[row].size(); ++j){
            int ng = mat[row][j];
            if(g != 0) ng = gcd(ng, g);
            int res =  solve(row + 1, ng, n, mat, dp) % mod;
            ans = (ans + res) % mod;
        }
        return dp[row][g] = ans;
    }
};