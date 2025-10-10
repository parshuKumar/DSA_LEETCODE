class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxi = INT_MIN;
         vector<int> dp(n);
        for(int i = n-1; i >= n - k; --i){
            dp[i] = energy[i];
        }
      
       for(int i = n-k-1; i >= 0;  --i){
            dp[i] = dp[i + k] + energy[i];
       }
       for(int i = 0;   i < n ; ++i){
            maxi = max(maxi, dp[i]);
       }
       return maxi;
    }

};