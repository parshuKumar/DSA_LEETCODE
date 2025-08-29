class Solution {
public:
    int m;
    int n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> v(m,vector<bool>(n,false));
        for(int i = 0; i < m ; ++i){
            for(int j = 0; j < n; ++j){
                if(v[i][j] == false && grid[i][j] != '0'){
                    cnt++;
                    // dfs(i , j, grid,v);
                    bfs(i, j, grid, v);
                }
                
            }
        }
        return cnt;
    }
    void dfs(int row, int col,vector<vector<char>>& grid , vector<vector<bool>> &v){
        if(row < 0 || row >= m || col < 0 || col >= n){
            return;
        }

        if(v[row][col] == true || grid[row][col] == '0'){
            return;
        }

        v[row][col] = true;

        dfs(row + 1, col, grid, v);
        dfs(row -1 , col , grid, v);
        dfs(row, col + 1, grid,v);
        dfs(row, col-1, grid,v);

    }

    void bfs(int row, int col, vector<vector<char>>& grid , vector<vector<bool>> &v){
        queue<pair<int, int>> q;
        q.push({row, col});
        v[row][col] = true;
       
       while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r+1 < m && v[r+1][c] == false && grid[r+1][c] != '0'){
                q.push({r+1, c});
                v[r+1][c] = true;
            }
            if(r-1 >= 0 && v[r-1][c] == false && grid[r-1][c] != '0'){
                q.push({r-1, c});
                v[r-1][c] = true;
            }
            if(c+1 < n && v[r][c+1] == false && grid[r][c+1] != '0'){
                q.push({r, c+1});
                v[r][c+1] = true;
            }
            if(c-1 >= 0 && v[r][c-1] == false && grid[r][c-1] != '0'){
                q.push({r, c-1});
                v[r][c-1] = true;
            }

       }
        
    }
};