class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));    
        return solve(0, 0, m, n);
    }

    int solve(int row, int col, int m, int n){
        if(row == m-1 && col == n-1) return 1;

        if(row >= m || col >= n) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int right = solve(row, col + 1, m , n);
        int down =  solve(row + 1, col, m , n);

        return dp[row][col] = right + down;
    }
};