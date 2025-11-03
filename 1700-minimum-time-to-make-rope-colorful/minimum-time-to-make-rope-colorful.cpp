class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prev = 0;
        int time = 0;

        for(int i = 0; i < n; ++i){
            
            if(i > 0 && colors[i] != colors[i - 1]) prev = 0;

            int cur = neededTime[i];

            time += min(prev, cur);
            prev = max(prev, cur);
        }

        return time;
    }
};