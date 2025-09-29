class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        int line[2051];
        for(int i = 0; i < n; ++i){
            line[logs[i][0]]++;
            line[logs[i][1]]--;
        }
        int res = 0;
        for(int i = 1950; i < 2050; ++i){
            line[i] += line[i - 1];
            res = line[i] > line[res] ? i : res;
        }
        return res;
    }
};