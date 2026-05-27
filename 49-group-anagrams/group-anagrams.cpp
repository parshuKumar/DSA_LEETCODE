class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 100log(100) = 100 * 7 = 700
        // 10 ^ 6  * 7 = if I sort each index.

        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < n; ++i){
            string newStr = strs[i];
            sort(newStr.begin(), newStr.end());
            mp[newStr].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto &a : mp){
            vector<string> sh;
            for(auto b : a.second){
                sh.push_back(b);
            }
            ans.push_back(sh);
        }
        return ans;
    }
};