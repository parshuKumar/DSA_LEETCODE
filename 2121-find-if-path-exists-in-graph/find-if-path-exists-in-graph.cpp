class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); ++i){
            int x = edges[i][0];
            int y = edges[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> vis(n, false);
        return dfs(source, destination, adj, vis);
       
    }

    bool dfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &vis){
        if(src == dest) return true;

        if(vis[src] == true) return false;

        vis[src] = true;

        for(int a : adj[src]){
            bool ans = dfs(a, dest, adj, vis);
            if(ans) return true;
        }

        return false;
    }
};