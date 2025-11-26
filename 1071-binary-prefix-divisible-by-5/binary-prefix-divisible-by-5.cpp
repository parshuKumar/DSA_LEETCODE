class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<bool> res(n);
        for(int i = 0; i < n; ++i){
            ans = (((ans * 2) % 5) + nums[i]);
             if( ans % 5  == 0){
                    res[i] = true;
             }else{
                res[i] = false;
             }
        }
        

        return res;
    }
};