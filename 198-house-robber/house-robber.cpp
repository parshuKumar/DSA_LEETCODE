class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n + 1, -1);
        // return solve(0, nums, dp);
        int prev = 0;
        int prev1 = nums[n-1];
        for(int i = n-2; i >= 0; --i){
           int pick = nums[i] + prev;
           int notPick = prev1;
           
           int ans = max(pick, notPick);

           prev = prev1;
           prev1 = ans; 

        }
        return prev1;
    }

    // int solve(int start, vector<int> &nums, vector<int> &dp){
    //     if( start >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[start] != -1) return dp[start];

    //     int pick = nums[start] + solve(start + 2, nums, dp);
    //     int notPick = solve(start +1, nums, dp);

    //     return dp[start] = max(pick, notPick);
    // }
};