class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> finishTime(n, 0);

        for(int i = 0; i < m; ++i){
            finishTime[0] += mana[i] * skill[0];

            for(int j = 1; j < n; ++j){
                finishTime[j] = max(finishTime[j], finishTime[j - 1]) + mana[i] * 1LL * skill[j];
            }

            for(int k = n-2; k >= 0; --k){
                int sub = mana[i] * 1LL * skill[k + 1];
                finishTime[k] = finishTime[k + 1] - sub;
            }
        }

        return finishTime[n-1];
    }
};