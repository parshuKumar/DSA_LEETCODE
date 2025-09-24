class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;

        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')'){
                if(st.empty() || s[st.top()] == ')'){
                    st.push(i);
                }
                else if (s[st.top()] == '('){
                    st.pop();
                }
            }
        }
        string ans;
        for(int i = n-1; i >= 0; --i){
            
            if(!st.empty() && i == st.top()){
                st.pop();
                continue;
            }

            ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};