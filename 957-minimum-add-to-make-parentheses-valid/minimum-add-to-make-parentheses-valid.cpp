class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int n  = s.size();
        stack<char> st;

        int cnt = 0;

        for(int i = 0; i < n; ++i){
            if(s[i] == '(') open++;
            
            if(s[i] == ')'){
                if(open <= 0){
                    close++;
                }else{
                    open--;
                }
            }
        }

        return (close  + open);
    }
};