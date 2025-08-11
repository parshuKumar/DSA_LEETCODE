class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt = 0;
        //if the first one then move the 1 to the last
        //if the second ones then move all the 1 to the first;

        for(int i =0; i < n; ++i){
            if(s[i] == '1') cnt++;            
        }

        for(int i = 0; i < n; ++i){
            if(cnt > 1){
                s[i] = '1';
                cnt--;
            }else{
                s[i] = '0';
            }

        }
        s[n-1] = '1';

        return s;
    }
};