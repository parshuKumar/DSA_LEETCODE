class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string ans;
        int open = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                ans.push_back(s[i]);
                open++;
            }
            else if(s[i] == ')'){

                if(open > 0){
                    ans.push_back(s[i]);
                    open--;
                }else{
                    continue;
                }
            }else{
                ans.push_back(s[i]);
            }
        }
        int m = ans.size();
        for(int i = m-1; i >= 0; --i){
            
           if(open == 0) break;

           if(ans[i] == '('){
                ans.erase(i, 1);
                open--;
           }
        }
        
        return ans;
        
    }
};