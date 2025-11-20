class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i = 1; i <= n; ++i){
            int a = i;
            int b = n - i;
            
            int vala = a, valb = b;
            bool checka = true, checkb = true;
            while(vala > 0){
                int digit = vala % 10;
                if(digit == 0){
                    checka = false;
                    break;
                }
                vala /= 10;
            }

            while(valb > 0){
                int digit = valb % 10;
                if(digit == 0){
                    checkb = false;
                    break;
                }
                valb /= 10;
            }
            if(checka && checkb) return {a, b};
        }

        return {};
    }
};