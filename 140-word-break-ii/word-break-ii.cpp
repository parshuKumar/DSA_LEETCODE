class Solution {
public:
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());
        string help;
        solve(0, s, st, help);
        return res;
    }

    void solve(int ind, string s, unordered_set<string>& st, string help) {
        if (ind == s.size()){
            res.push_back(help);
            return;
        }

        for (int l = 1; l <= s.size() - ind; ++l) {
            string curword = s.substr(ind, l);
            
            if (st.contains(curword)){
                solve(ind + l, s, st, help + curword + (l == s.size()-ind ? "" : " "));
            }      
        }
    }
};