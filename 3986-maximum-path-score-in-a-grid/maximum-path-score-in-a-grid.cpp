class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        
        vector<vector<vector<int>>> dp(grid.size() + 1, vector<vector<int>> (grid[0].size() + 1, vector<int>(k + 1, -1)));
        int ans =  solve(grid, 0, 0, k, dp);
        return (ans < 0 ? -1 : ans);
    }
    

    int solve(vector<vector<int>>& grid, int row, int col, int k, vector<vector<vector<int>>> &dp){
         

        if(row >= grid.size() || col >= grid[row].size()){
            return -1e9;
        }   

        int value = (grid[row][col] == 0 ? 0 : 1);
        k -= value;
        if(k < 0) return -1e9;

        if(row == grid.size() - 1 && col == grid[0].size() - 1){
            return grid[row][col];
        }

        if(dp[row][col][k] != -1) return dp[row][col][k];

        int down = solve(grid, row + 1, col, k, dp);
        int right = solve(grid, row, col + 1, k, dp);

        int best = max(down, right);
        return dp[row][col][k] = (best == -1e9 ? -1e9 : grid[row][col] + best); 
    }


};