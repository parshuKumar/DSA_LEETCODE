class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int in = image[sr][sc];
        if(in == color) return image;
        dfs(image, sr, sc, color, in);
        return image;

    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int in){
        
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return;
        }

        if(image[sr][sc] != in){
            return;
        }

        image[sr][sc] = color;
        
        dfs(image, sr-1, sc, color, in);
       
        dfs(image, sr+1, sc, color, in);
       
        dfs(image, sr, sc+1, color, in);
        
        dfs(image, sr, sc-1, color, in);
        
    }
};