class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.assign(grid.size() + 1, vector<vector<int>> (grid[0].size() + 1, vector<int> (k, -1)));
        return solve(0, 0, 0, grid, k);
    }

    int solve(int row, int col, int pathSumMod, vector<vector<int>> &grid, int k){
        if(row >= grid.size() || col >= grid[0].size()){
            return 0;
        }

        if(row == grid.size() - 1 && col == grid[0].size() - 1){
            if((grid[row][col] + pathSumMod) % k == 0) return 1;
            return 0;
        }

        if(dp[row][col][pathSumMod] != -1) return dp[row][col][pathSumMod];

        int down = solve(row + 1, col, (pathSumMod + grid[row][col]) % k,grid, k);
        int right = solve(row, col + 1, (pathSumMod + grid[row][col]) % k, grid, k);

        return dp[row][col][pathSumMod] = (down + right) % MOD;
    }
};