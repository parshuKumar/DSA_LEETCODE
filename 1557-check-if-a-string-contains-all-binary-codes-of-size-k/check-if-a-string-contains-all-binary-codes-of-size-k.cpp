class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = pow(2, k);
        set<string> st;
        
        for(int i = k; i <= s.size(); ++i){
            string cur = s.substr(i - k, k);
            st.insert(cur);
        }

        return (st.size() == total ? true : false); 
    }
};