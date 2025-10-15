class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        for(int i = 0; i < n; ++i){
            if(ans.empty()){ 
                ans.push_back(words[i]);
                continue;
            }
           string help = ans.back();
           sort(help.begin(), help.end());
           string trialWord = words[i];
           sort(trialWord.begin(), trialWord.end());
           if(help != trialWord) ans.push_back(words[i]);
        }
        return ans;
    }
    
};