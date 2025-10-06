class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> num = nums;
        num.insert(num.end(), nums.begin(), nums.end());
        int n = nums.size();
        int cnt1 = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 1) cnt1++;
        }

        int left = 0, right = cnt1;
        int cnt0 = 0;
        for(int i = 0; i < right; ++i){
            if(nums[i] == 0) cnt0++;
        } 
        int mini = cnt0;
        for(; right < num.size(); ++right){
            if(num[right] == 1) cnt1++;
            else cnt0++;

            if(num[left] == 1) cnt1--;
            else cnt0--;

            if(cnt0 < mini){
                mini = cnt0;
            }
            left++;
        }
        return mini;
    }
};