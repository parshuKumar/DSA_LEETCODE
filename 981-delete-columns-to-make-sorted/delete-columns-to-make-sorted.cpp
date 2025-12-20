class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size();
        int res = 0;

        for(int i = 0; i < strs[0].size(); ++i){
            char c = strs[0][i];
            for(int j = 0; j < n; ++j){
                if(strs[j][i] < c){
                    res++;
                    break;
                }
                c = strs[j][i];
            }
        }
        return res;
    }
};