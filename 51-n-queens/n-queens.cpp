class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        solve(0, n , res, ans);
        return ans;
    }
    bool isSafe(int row, int col, int n, vector<vector<string>> &res){
        
        for(int i = 0; i < row; ++i)
            if(res[i][col] == "Q") return false;

        // upper-left diagonal
        for(int i = row-1, j = col-1; i>=0 && j>=0; --i, --j)
            if(res[i][j] == "Q") return false;

        // upper-right diagonal
        for(int i = row-1, j = col+1; i>=0 && j<n; --i, ++j)
            if(res[i][j] == "Q") return false;        

        return true;
    }
    void solve(int row, int n, vector<vector<string>> &res,  vector<vector<string>> &ans){
        if(row >= n){
            
            vector<string> board;
            for(int i = 0; i < n; ++i){
                string rowstr = "";
                for(int j = 0; j < n; ++j){
                    rowstr += res[i][j];
                }
                board.push_back(rowstr);
            }
            ans.push_back(board);
            return;

        }

        for(int col = 0; col < n; ++col){

            if(isSafe(row, col, n, res)){
                res[row][col] = "Q";
                solve(row + 1, n, res, ans);
                res[row][col] = ".";
            }
        }
    }


};