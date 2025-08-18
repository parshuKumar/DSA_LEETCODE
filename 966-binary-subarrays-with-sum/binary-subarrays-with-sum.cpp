class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int ans = solve(nums, goal) - solve(nums, goal - 1);  
        return ans;

    }

      int solve(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.size();
        int left = 0, right = 0, sum = 0, cnt = 0;

        for(; right < n; ++right){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;

    }
};