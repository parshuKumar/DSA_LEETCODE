class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjList(n);

        for(auto cur : edges){
            adjList[cur[0]].push_back(cur[1]);
            adjList[cur[1]].push_back(cur[0]);
        }

        return solve(0, -1, adjList, hasApple);
      
    }
    int solve(int ind, int parent, vector<vector<int>> &adjList, vector<bool>& hasApple){
        int totalTime = 0;

        for(auto neighbour : adjList[ind]){
            if(neighbour == parent) continue;
            int curTime = solve(neighbour, ind, adjList, hasApple);
            if(hasApple[neighbour] || curTime > 0){
                totalTime += curTime + 2;
            }
        }
        return totalTime;
    }
};