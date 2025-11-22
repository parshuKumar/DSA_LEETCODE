class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> v(26);
        int n = s.size();
        for(char i = 'a'; i <= 'z'; ++i){
            bool found = false;
            int fir = -1, las = -1;
            for(int j = 0; j < n; ++j){

                if(!found && s[j] == i){
                    found = true;
                    fir = j;
                }else if(found && s[j] == i){
                    las = j;
                }
            }
            v[i - 'a'] = {fir, las};
        }
        int result = 0;
        for(int i = 0; i < 26; ++i){
            int start = v[i].first;
            int last = v[i].second;

            if(start == -1 || last == -1) continue;
            set<char> st;
            for(int j = start + 1; j < last; ++j){
                st.insert(s[j]);
            }

            result += st.size();
        }
        return result;
    }
};