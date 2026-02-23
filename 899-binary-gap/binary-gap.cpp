class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int cur = 0;
        int longDist = 0;

        string num = convertToString(n);
        cout << num ;
        for(int i = 0; i < num.size(); ++i){
            if(num[i] == '1'){
                if(prev != -1)
                    longDist = max(longDist, i - prev);
                prev = i;
            }
        }
        return longDist;
    }

    string convertToString(int n){
        string s = "";
        while(n > 0){
            if((n & 1) == 1){
                s += "1";
            }else{
                s += "0";
            }

            n >>= 1;
        }
        reverse(s.begin(), s.end());

        return s;
    }
};