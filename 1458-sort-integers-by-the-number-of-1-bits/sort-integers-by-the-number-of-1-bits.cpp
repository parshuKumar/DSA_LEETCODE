class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [this](int a , int b){
            int bitsa = cntOnes(a);
            int bitsb = cntOnes(b);

            if(bitsa == bitsb){
                return a < b;
            }

            return bitsa < bitsb;
        });

        return arr;
    }

    int cntOnes(int num){
        int total = 0;
        while(num > 0){
            if(num & 1 == 1) total++;

            num >>=1;
        }
        return total;
    }
};

