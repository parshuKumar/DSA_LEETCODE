class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> diff(nums.size(), 0);
        for(int i = 0; i < n; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
        

            diff[l] -= 1;
            if(r + 1 < diff.size()) diff[r + 1] += 1;
        }
        int cur = 0;
        for(int i = 0; i < nums.size(); ++i){
            cur += diff[i];
            nums[i] += cur;
            if(nums[i] > 0) return false;
        }

        return true;

    }
};