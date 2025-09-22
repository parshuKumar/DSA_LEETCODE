class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        int freq = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        
        for(int right = 0; right < n; ++right){

            if(nums[right] == maxi){
                freq++;
            }

            while(freq == k){
                ans = ans + (n - right);
                if(nums[left] == maxi){
                    freq--;
                }
                left++;
            }

        }
        return ans;
    }
};