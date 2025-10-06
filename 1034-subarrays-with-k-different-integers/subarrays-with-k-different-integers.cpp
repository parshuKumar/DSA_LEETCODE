class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = atmost(nums, k) - atmost(nums, k-1);
        return ans;
    }

    int atmost(vector<int> &nums, int k){
        unordered_map<int, int> mp;
        int left = 0, n = nums.size();
        int cnt = 0;
        for(int right = 0; right < n; ++right){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            cnt += (right - left + 1);
        }
        cout << cnt << " ";
        return cnt;
    }
};