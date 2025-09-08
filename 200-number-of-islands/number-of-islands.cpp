class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, true));
        for(int i = 0; i < m; ++i){ 
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1' && vis[i][j] == true){
                    cnt++;
                    bfs(i, j, grid,vis);
                }
            }
        }
        return cnt;    
    }
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = false;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            //down checking
            if(r+1 < n && vis[r+1][c] == true && grid[r+1][c] == '1' ){
                q.push({r+1, c});
                vis[r+1][c] = false;
            }
            //right checking
            if(c+1 < m && vis[r][c+1] == true && grid[r][c+1] == '1' ){
                q.push({r, c+1});
                vis[r][c+1] = false;
            }
            //up checking
             if(r-1 >= 0 && vis[r-1][c] == true && grid[r-1][c] == '1' ){
                q.push({r-1, c});
                vis[r-1][c] = false;
            }

            //left checking
              if(c-1 >= 0 && vis[r][c-1] == true && grid[r][c-1] == '1' ){
                q.push({r, c-1});
                vis[r][c-1] = false;
            }
        }
    }
};