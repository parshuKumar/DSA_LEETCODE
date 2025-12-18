class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long sum = 0;        
        //poora calculate
        for(int i = 0; i < n; ++i){
            sum += prices[i] * strategy[i];
        }

        long long ans = sum;
        for(int i = 0; i < k; ++i){
           sum -= prices[i] * strategy[i];
           if(i >= k/2){
                sum += prices[i];
           }
        }

        ans = max(ans, sum);
        
        for(int i = k; i < n; ++i){
            //right location removed and then added;
            sum -= prices[i] * strategy[i];
            sum += prices[i];

            //left side location added again
            sum += prices[i - k] * strategy[i - k];

            //removing the middle location
            sum -= prices[i - k/2];

            ans = max(ans, sum);
        }

        return ans;
    }
};