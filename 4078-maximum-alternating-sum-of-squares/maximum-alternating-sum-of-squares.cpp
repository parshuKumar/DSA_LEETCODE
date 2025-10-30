class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 0; i < n / 2; ++i){
            res += (nums[n - i - 1] - nums[i]);
            // cout << res << " ";
        }

        if(n & 1 == 1){
            res += nums[n / 2];
        }

        return res;
    }

};