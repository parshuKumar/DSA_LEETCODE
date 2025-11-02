class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < dislikes.size(); ++i) {
            int x = dislikes[i][0];
            int y = dislikes[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> visited(n + 1, -1);

        for (int i = 1; i <= n; ++i) {
            if (visited[i] == -1) {
                if(!dfs(i, 0, adj, visited)) return false;
            }
        }

        return true;
    }

    bool dfs(int ind, int color, vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[ind] = color;

        for (auto& neighbour : adj[ind]) {

            if (visited[ind] == visited[neighbour])
                return false;

            if (visited[neighbour] == -1) {
                if (!dfs(neighbour, 1 - color, adj, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};