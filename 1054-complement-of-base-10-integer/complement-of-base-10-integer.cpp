class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int ans = findingComplement(n);
        
        return ans;
    }

    int findingComplement(int n) {
        int power = 0;
        int curBinary = 0;

        int sol = 0;
        while (n > 0) {
            if (n & 1 == 1)
                curBinary = 0;
            else
                curBinary = 1;
            sol += (int)pow(2, power++) * curBinary;
            n >>= 1;
        }
        return sol;
    }
};