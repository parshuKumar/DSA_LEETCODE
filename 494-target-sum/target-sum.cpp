class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
       
        for(int a : nums) sum += a;

        if(target > sum || target < -sum) return 0;
         vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        return solve(0, nums, target, dp, sum);
    }

    int solve(int start, vector<int> &nums, int target, vector<vector<int>> &dp, int offset){
       
        if(start == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }
        
        int shiftTarget = target + offset;
        if(shiftTarget < 0 || shiftTarget > 2*offset) return 0;
        if(dp[start][shiftTarget] != -1) return dp[start][shiftTarget];
        //taking - sign
        int negSign = solve(start+1, nums, target + nums[start], dp, offset);

        //taking the + sign
        int posSign = solve(start + 1, nums, target - nums[start], dp, offset);

        return dp[start][shiftTarget] = negSign + posSign;
    }
};