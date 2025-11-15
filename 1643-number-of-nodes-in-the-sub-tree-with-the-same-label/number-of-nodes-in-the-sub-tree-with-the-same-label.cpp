class Solution {
public:
    vector<int> res;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        res.resize(n, 0);
        vector<vector<int>> adjList(n);

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        solve(0, adjList, labels , -1);

        return res;
    }

    vector<int> solve(int ind, vector<vector<int>> & adjList, string &labels, int parent) {
        vector<int> alph(26, 0);

        char mylabel = labels[ind];
        alph[mylabel - 'a']++;

        for (int neigh : adjList[ind]) {
            if(neigh == parent) continue;
            vector<int> childcnt = solve(neigh, adjList, labels, ind);
            
            for(int i = 0; i < 26; ++i){
                alph[i] += childcnt[i];
            }
        }
        res[ind] = alph[mylabel - 'a'];
        return alph;
    }
};