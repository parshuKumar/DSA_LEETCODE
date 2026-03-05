class Solution {
public:
    int minOperations(string s) {
        char prev1 = s[0];
        char prev = (s[0] == '0' ? '1' : '0');
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i < s.size(); ++i){
            char cur = s[i];
            if(i % 2 == 0){
                if(cur != prev1) ans1++;
            }else{
                if(cur != prev) ans1++;
            }
        }

        for(int i = 0; i < s.size(); ++i){
            char cur = s[i];
            if(i % 2 == 0){
                if(cur != prev){
                    ans2++;
                }
            }else{
                if(cur != prev1) ans2++;
            }
        }
        // cout << ans1 << " " << ans2;
        return min(ans1, ans2);
    }
};