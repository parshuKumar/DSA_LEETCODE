class Solution {
public:
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) {
        // vector<vector<int>> ans;
        // vector<int> help;
       memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, n, nums, target);

        // for(auto a : ans){
        //     for(int b : a){
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }

    }

    int solve(int start , int end, vector<int> &nums, int target){

        if(target == 0){
            // ans.push_back(help);
            return 1;
        }
        if(target < 0){
            return 0;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int cnt = 0;
        for(int i = 0; i < end; ++i){
            // help.push_back(nums[i]);
            cnt += solve(i, end, nums, target - nums[i]);
            // help.pop_back();
        }
        dp[target] = cnt;
        return cnt;
    }
};