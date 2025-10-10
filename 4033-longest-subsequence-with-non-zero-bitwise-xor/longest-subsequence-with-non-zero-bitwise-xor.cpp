class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xora = 0;
        // int maxl = INT_MIN;
        int n = nums.size(), left = 0;
        bool allZero = true;
        for(int right = 0; right < n; ++right){
            xora ^= nums[right];
            if(nums[right] != 0) allZero = false;
        }
        if(allZero) return 0;
        return xora != 0 ? n : n-1;
    }
};