class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, -1);
        dp[n + 1] = 0;
        dp[n] = 0;
        for(int i = n-1; i >= 0; --i){
            int pick = nums[i] + dp[i + 2];
            int noPick = 0 + dp[i+1];
            dp[i] = max(pick, noPick);
        }
        return dp[0];
        // return ans;
    }

    // int solve(int start, vector<int> &nums, vector<int> &dp){

    //     if(start >= nums.size()){
    //         return 0;
    //     }

    //     if(dp[start] != -1) return dp[start];

    //     //pick
    //     int pick = nums[start] + solve(start + 2, nums,dp);

    //     //nopick
    //     int noPick = 0 + solve(start + 1, nums, dp);

    //     return dp[start] = max(pick, noPick);
    // }
};