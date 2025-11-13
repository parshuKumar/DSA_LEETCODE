class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pre(1001, 0);
        int n = trips.size();

        for(int i = 0; i < n; ++i){
            int from = trips[i][1];
            int to = trips[i][2];
            int val = trips[i][0];

            pre[from] += val;
            pre[to] -= val;
        }

        for(int i = 0; i < 1001; ++i){

            if(i > 0) pre[i] = pre[i] + pre[i - 1];

            if(pre[i] > capacity) return false;
        }

        return true;
    }
};