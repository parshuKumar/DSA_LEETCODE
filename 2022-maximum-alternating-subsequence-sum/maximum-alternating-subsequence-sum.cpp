class Solution {
public:
    long long dp[100001][2];
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, true);
    }

    long long solve(int ind, vector<int> &nums, bool flag){
        if(ind >= nums.size()){
            return 0;    
        }

        if(dp[ind][flag] != -1) return dp[ind][flag];
        long long take = (flag ? nums[ind] : -nums[ind]) + solve(ind + 1, nums, !flag);

        long long notTake = solve(ind + 1, nums, flag);
       

        return dp[ind][flag] = max(take , notTake);
    }
};