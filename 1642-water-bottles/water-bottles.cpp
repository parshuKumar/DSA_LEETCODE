class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;

        while(numBottles >= numExchange){
            int k = numBottles / numExchange;
            ans += numExchange * k;
            numBottles -= numExchange * k;

            numBottles += k;
        }

        return ans + numBottles;
    }
};