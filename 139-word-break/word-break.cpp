class Solution {
public:
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        dp.resize(s.size() + 1, -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(0, s, st);
    }

    bool solve(int ind, string s, unordered_set<string> &st){
        if(ind == s.size()) return true;

        for(int l = 1; l <= s.size(); ++l){
            string curword = s.substr(ind, l);
            if(dp[ind] != -1) return dp[ind];
            if(st.contains(curword) && solve(ind + l, s, st)) return dp[ind] = true;
        }

        return dp[ind] = false;
    }
};