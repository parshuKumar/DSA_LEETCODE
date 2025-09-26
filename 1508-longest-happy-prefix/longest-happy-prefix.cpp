class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        string ans = "";
        int len = 0;
        vector<int> lps(n,0);
        lps[0] = 0;
        int i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        ans = s.substr(0, lps[n-1]);
        return ans;
    }
};