class Solution {
public:
    int minAddToMakeValid(string s) {

        int n  = s.size();
        stack<char> st;

        int cnt = 0;

        for(int i = 0; i < n; ++i){
            if(s[i] == '(') st.push(s[i]);

            if(s[i] == ')'){
                if(st.empty()){
                    cnt++;
                }else{
                    st.pop();
                }
            }
        }

        if(!st.empty()) cnt += st.size();

        return cnt;
    }
};