class Solution {
public:
    int m;
    int n;
    int numSpecial(vector<vector<int>>& mat) {
        
        m = mat.size();
        n = mat[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 1){
                    bool row = checkRows(i, mat);
                    bool col = checkCol(j, mat);

                    if(row && col) ans++; 
                }
            }
        }
        return ans;
    }

    bool checkRows(int row, vector<vector<int>> &mat){
        int ones = 0;
        for(int i = 0; i < n; ++i){
            if(mat[row][i] == 1){
                ones++;
            }
        }
        return ((ones == 1) ? true : false);
    }

    bool checkCol(int col, vector<vector<int>> &mat){
        int ones = 0;
        for(int i = 0; i < m; ++i){
            if(mat[i][col] == 1){
                ones++;
            }
        }
        return ((ones == 1) ? true : false);
    }
};