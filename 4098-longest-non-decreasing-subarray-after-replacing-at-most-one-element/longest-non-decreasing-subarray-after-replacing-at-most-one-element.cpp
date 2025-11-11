class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), suff(n, 1);

        for(int i = 1; i < n; ++i){
            if(nums[i] >= nums[i - 1])
                pre[i] += pre[i - 1]; 
        }

        for(int i = n - 2; i >= 0; --i){
            if(nums[i] <= nums[i + 1]){
                suff[i] += suff[i + 1];
            }
        }
        //there are two conditions; 
        //one we can just change the first or last element of the subarray
        //one that we change any 1 elemnet to merge the two increasing subarray

        int res = min(n, *max_element(pre.begin(), pre.end()) + 1);
        for(int i = 1; i < n - 1; ++i){
            
            if(nums[i - 1] <= nums[i + 1]){
                res = max(res, pre[i - 1] + suff[i + 1] + 1);
            }
        }
        return res;
    }
};