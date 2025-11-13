class Solution {
public:
    int maxOperations(string s) {
        
        int n = s.size();
        int oper = 0;
        vector<int> pre(n, 0);
        pre[0] = (s[0] == '1' ? 1 : 0);
        for(int i = 1; i < n; ++i){
            pre[i] = pre[i -1] + (s[i] == '1' ? 1 : 0);
        }

        for(int i = 1; i < n; ++i){
            if(s[i] == '0' && (s[i + 1] == '1' || i == n-1)){
                oper += pre[i];
            }
        }
        return oper;
        
    }
};