class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
    
        if(fresh == 0) return 0;
        int min = -1;
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int size = q.size();
            min++;
            for(int i = 0;  i < size; ++i){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(auto &d : dirs){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < m && nr >= 0 && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }
    
        return fresh == 0 ? min : -1;
    }
};