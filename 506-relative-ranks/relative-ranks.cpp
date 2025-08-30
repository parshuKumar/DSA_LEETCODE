class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> help(score.begin(), score.end());

        sort(help.begin(), help.end(), greater<int>());

        unordered_map<int, int> mp;

        for(int i = 0; i < help.size(); ++i){
            mp[help[i]] = i + 1;
        }

        vector<string> ans;

        for(auto a : score){
            if(mp[a] == 1) ans.push_back("Gold Medal");
            else if(mp[a] == 2) ans.push_back("Silver Medal");
            else if (mp[a] == 3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mp[a]));
        }
        return ans;

    }
};