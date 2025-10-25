class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> freq(maxi + 1, 0);
        
        for(int i = 0; i < n;  ++i){
            freq[nums[i]]++;
        }
        for(int i = 1; i < freq.size(); ++i){
            freq[i] += freq[i - 1];
        }
        int ans = -1;
        for(int target = 0; target <= maxi; ++target){
            
            if(freq[target] == 0) continue;
             
            int left = (target - k > 0 ? target - k : 0), right = (target + k < maxi ? target + k : maxi);

            int total = freq[right] - (left > 0 ? freq[left - 1] : 0);

            int targetfreq = freq[target] - (target > 0 ? freq[target - 1] : 0);;

            int needConver = min(numOperations, total - targetfreq);

            ans = max(ans, targetfreq + needConver);
        }

        return ans;
    }
};