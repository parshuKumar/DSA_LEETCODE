class Solution {
public:
    int numSteps(string s) {
        
        int cnt = 0;
        
        while(s.size() > 1){
            if(s[s.size() - 1] == '1'){
                addOne(s);
            }else{
                s.pop_back();
            }
            cnt++;
            // cout << cnt << " " << s << " " << endl;
        }
        return cnt;
    }

    void addOne(string &s){
        int carry = 1;
        int i = s.size() - 1;
        while(carry > 0 && i >= 0){
            if(s[i] == '1'){
                s[i] = '0';
            }
            else{
                s[i] = '1';
                carry = 0;
            }
            i--;
        }
        if(carry == 1){
            s = '1' + s;
        }
    }
};