class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        if(sum > num * 9) return "";
        int curSum = sum;
        for(int i = 0; i < num; ++i){
            int value = min(9, curSum);
            ans += (value + '0');
            curSum -= value;
        }
        return ans;
    }
};