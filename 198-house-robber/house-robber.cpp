class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = solve(0, nums, dp);
        return ans;
    }

    int solve(int start, vector<int> &nums, vector<int> &dp){

        if(start >= nums.size()){
            return 0;
        }

        if(dp[start] != -1) return dp[start];

        //pick
        int pick = nums[start] + solve(start + 2, nums,dp);

        //nopick
        int noPick = 0 + solve(start + 1, nums, dp);

        return dp[start] = max(pick, noPick);
    }
};