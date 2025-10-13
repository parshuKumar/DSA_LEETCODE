class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxL = 0;
        for(int i = 0; i < n; ++i){
            vector<int> mp(26, 0);
            for(int j = i; j < n; ++j){
                mp[s[j] - 'a']++;
                int curCnt = mp[s[j] - 'a'];
                bool check = true;
                for(int k = 0; k < 26; ++k){
                    if(mp[k] == 0) continue;
                    if(mp[k] != curCnt){
                        check = false;
                        break;
                    }
                }
                if(check){
                    maxL = max(maxL, j - i + 1);
                }
                
            }
        }
        return maxL;
    }
};