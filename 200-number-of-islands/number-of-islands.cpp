class Solution {
public:
    int n;
    int m;
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(visited[i][j] == true || grid[i][j] == '0') continue;
                cnt++;
                dfs(i, j, grid, visited);
            }
        }
        return cnt;
    }

    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0' || visited[row][col] == true){
            return;
        }

        visited[row][col] = true;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k = 0; k < 4; ++k){
            dfs(row + dr[k], col + dc[k], grid, visited);
        }

    }
};