class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int total = 0;
        for(int i = left; i <= right; ++i){
            int num = i;
            int cnt = 0;
            while(num > 0){
                if((num & 1) == 1){
                    cnt++;
                }
                num = num >> 1;
            }
            if(checkPrime(cnt)){
                total++;
            }
        }
        return total;
    }

    bool checkPrime(int num){
        if(num < 2) return false;
        for(int i = 2; i < num; ++i){
            if(num % i == 0) return false;
        }
        return true;
    }
};