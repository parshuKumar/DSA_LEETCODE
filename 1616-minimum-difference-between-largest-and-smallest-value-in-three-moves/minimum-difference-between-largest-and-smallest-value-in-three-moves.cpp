class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;

        sort(nums.begin(), nums.end());

        int a = abs(nums[3] - nums[n-1]);
        int b = abs(nums[n-4] - nums[0]);
        int c = abs(nums[n-2] - nums[2]);
        int d = abs(nums[n-3] - nums[1]);
        return min(min((min(a, b)), c),d);
    }
};