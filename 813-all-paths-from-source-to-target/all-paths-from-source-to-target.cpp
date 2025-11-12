class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> help = {0};
        solve(graph, 0, res, help);   

        return res;
        
    }

    void solve(vector<vector<int>>& graph, int ind, vector<vector<int>> &res, vector<int> &help){

        if(ind == graph.size()-1){
            res.push_back(help);
            return;
        }

        for(int neighbour : graph[ind]){
            help.push_back(neighbour);
            solve(graph, neighbour, res, help);
            help.pop_back();
        }

    }
};