class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == original){
                original <<= 1;
            }
        }
        return original;
    }
};