class Solution {
public:

    int UNGUARDED = 0;
    int GUARDED = 1;
    int GUARDS = 2;
    int WALLS = 3;
    int row, col;

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        row = m;
        col = n;

        vector<vector<int>> mat(m, vector<int> (n , 0));

        for(int i = 0; i < guards.size(); ++i){
            int x = guards[i][0];
            int y = guards[i][1];
            mat[x][y] = GUARDS;
        }

        for(int i = 0; i < walls.size(); ++i){
            int x = walls[i][0];
            int y = walls[i][1];

            mat[x][y] = WALLS;
        }

        for(int i = 0; i < guards.size(); ++i){
            int x = guards[i][0];
            int y = guards[i][1];

            makeGuarded(x, y, mat);
        }

        int ans = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                
                //if UNGUARDED
                cout << mat[i][j] << " ";
                if(mat[i][j] == UNGUARDED) ans++;
               

            }
            cout << endl;
        }

        return ans;

    }

    void makeGuarded(int x , int y, vector<vector<int>> &mat){

        //up
        for(int i = x - 1; i >= 0; --i){
            if(mat[i][y] == UNGUARDED) mat[i][y] = GUARDED;
             else if(mat[i][y] == WALLS || mat[i][y] == GUARDS) break;
        }

        //down
        for(int i = x + 1; i < row; ++i){
            if(mat[i][y] == UNGUARDED) mat[i][y] = GUARDED;  
            else if(mat[i][y] == WALLS || mat[i][y] == GUARDS) break;
        }

        //left
        for(int j = y - 1; j >= 0; --j){
            if(mat[x][j] == UNGUARDED) mat[x][j] = GUARDED;
            else if(mat[x][j] == WALLS || mat[x][j] == GUARDS) break;
        }

        //right
        for(int j = y + 1; j < col; ++j){
            if(mat[x][j] == UNGUARDED) mat[x][j] = GUARDED;
            else if(mat[x][j] == WALLS || mat[x][j] == GUARDS) break;
        }
    }
};