class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; ++i){
            int to = edges[i][0];
            int from = edges[i][1];

            mp[to]++;
            mp[from]++;

            if(mp[to] == n){
                return to;
            }
            if(mp[from] == n){
                return from;
            }

        }
        return -1;
    }
};