class Solution {
public:
    const int MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        string s = "";
        for(int i = 1; i <= n; ++i){
            string cur = convertToBinary(i);
            s += cur;
        }    
        return convertToDecimal(s);
        return 0;
    }

    string convertToBinary(int num){
        string ans;
        while(num > 0){
            if(num % 2 == 0) ans.push_back('0');
            else ans.push_back('1');
            num = num / 2;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }

    int convertToDecimal(string &num){
        int total = 0;
        int twoPower = 1;
        for(int i = num.size() - 1; i >= 0; --i){
            if(num[i] == '1'){
                total = (total + twoPower) % MOD;
            }
            twoPower = (twoPower * 2) % MOD;
        }
        return total;
    }

};