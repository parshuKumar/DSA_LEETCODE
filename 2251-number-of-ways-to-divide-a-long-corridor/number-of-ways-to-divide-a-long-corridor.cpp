class Solution {
public:
    int numberOfWays(string s) {
        const int MOD = 1e9 + 7;
        int res = 1;
        int cnts = 0, cntp = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'S') {
                cnts++;
                if(cnts > 2){
                    res  = ((res * (cntp + 1LL)) % MOD);
                    cntp = 0;
                    cnts = (cnts % 2);
                }  
            } else {
                if(cnts == 2){
                    cntp++;
                }
            }
        }
        if(cnts < 2) return 0;
        return res;
    }
};