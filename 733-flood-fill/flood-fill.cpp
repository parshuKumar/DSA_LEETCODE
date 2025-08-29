class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int in = image[sr][sc];
        if(in == color) return image;
        // dfs(image, sr, sc, color, in);
        bfs(image, sr, sc, color, in);
        return image;

    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int in){
        
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return;
        }

        if(image[sr][sc] != in || image[sr][sc] == color){
            return;
        }

        image[sr][sc] = color;
        
        dfs(image, sr-1, sc, color, in);
       
        dfs(image, sr+1, sc, color, in);
       
        dfs(image, sr, sc+1, color, in);
        
        dfs(image, sr, sc-1, color, in);
        
    }

    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int ini){
        queue<pair<int, int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row+1 < image.size() && image[row+1][col] == ini){
                q.push({row+1,col});
                image[row+1][col] = color;
            }
            if(row - 1 >= 0 && image[row-1][col] == ini){
                 q.push({row-1,col});
                 image[row-1][col] = color;
            }
            if(col + 1 < image[0].size() && image[row][col+1] == ini){
                 q.push({row,col+1});
                 image[row][col+1] = color;
            }
            if(col - 1 >= 0 && image[row][col-1] == ini){
                 q.push({row,col-1});
                 image[row][col-1] = color;
            }
        }
    }

};