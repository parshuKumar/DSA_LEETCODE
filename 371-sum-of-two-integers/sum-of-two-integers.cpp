class Solution {
public:
    int getSum(int a, int b) {

        while(b != 0){
            int xora = (a ^ b);
            b = a & b;
            a = xora;
            b <<= 1;
        }

        return a;
    }
};