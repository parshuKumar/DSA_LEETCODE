class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int mr = maze.size();
        int mc = maze[0].size();

        queue<pair<int , int>> q;

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int step = 0;
        while(!q.empty()){
            int n = q.size();
            
            for(int i = 0; i < n; ++i){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                if(!(row == entrance[0] && col == entrance[1]) && (row == mr-1 || col == mc-1 || row == 0 || col == 0)){
                    return step;
                }

                if(row + 1 < mr && maze[row + 1][col] == '.'){
                    q.push({row + 1, col});
                    maze[row + 1][col] = '+';
                }
                if(row -1 >= 0 && maze[row - 1][col] == '.'){
                    q.push({row - 1, col});
                    maze[row - 1][col] = '+';
                }
                if(col + 1 < mc && maze[row][col + 1] == '.'){
                    q.push({row, col + 1});
                    maze[row][col + 1] = '+';
                }
                if(col - 1 >= 0 && maze[row][col - 1] == '.'){
                    q.push({row, col - 1});
                    maze[row][col - 1] = '+';
                }
            }

            step++;
            
        }
        return -1;
    }
};