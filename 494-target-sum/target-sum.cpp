class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(0, nums, target);
    }

    int solve(int start, vector<int> &nums, int target){
       
        if(start >= nums.size()){
            if(target == 0) return 1;
            else return 0;
        }

        //taking - sign
        int negSign = solve(start+1, nums, target - (nums[start] * -1));

        //taking the + sign
        int posSign = solve(start + 1, nums, target - nums[start]);

        return negSign + posSign;
    }
};