class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int mon = 1;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += mon;
            cnt++;
            mon++;
            if(cnt == 7){
                mon = mon - 7 + 1;
                cnt = 0;
            }
        }
        return ans;
    }
};