class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int ind = -1;
        for(int i = 0;i < n; ++i){
            if(nums[i] == 1){
                ind = i;
                break;
            }
        }
        if(ind == -1) return true;
        int cnt = 0;
        for(int i = ind + 1; i <  n; ++i){
            if(nums[i] == 0){
                cnt++;
            }else{
                if(cnt < k) return false;
                cnt = 0;
            }
        }
        return true;
    }
};