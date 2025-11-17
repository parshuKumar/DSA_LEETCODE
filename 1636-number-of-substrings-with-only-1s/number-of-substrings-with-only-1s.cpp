class Solution {
public:
    const int M = 1e9 + 7;
    int numSub(string s) {
        int total = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1'){
                cnt++;
            }else{
                total += ((((cnt % M) * 1LL * ((cnt + 1) % M)) % M) / 2);
                cnt = 0;
            }
        }   
        if(cnt > 0){
            total += ((((cnt % M) * ((cnt + 1) % M)) % M) / 2);
        }
        return total;
    }
};