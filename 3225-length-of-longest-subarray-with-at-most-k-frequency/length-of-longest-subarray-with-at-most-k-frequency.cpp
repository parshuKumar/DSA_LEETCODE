class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int left = 0, right = 0;
        int maxi = 0;
        for(int right = 0; right < n; ++right){
            mp[nums[right]]++;
           
            while(mp[nums[right]] > k){
                
                mp[nums[left]]--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
            
        }
        return maxi;
    }
};