class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1, -1));
        return solve(0, -1, nums, dp);
    }

    int solve(int cur, int prev, vector<int> &nums,vector<vector<int>> &dp){
        if(cur >= nums.size()){
            return 0;
        }
        if(dp[prev + 1][cur] != -1) return dp[prev + 1][cur];
        int take = 0;
        if(prev == -1 || cur - prev != 1) take = nums[cur] + solve(cur + 1, cur, nums, dp);
        int nottake = solve(cur + 1, prev, nums, dp);

        return dp[prev + 1][cur] = max(take, nottake);
    }
};