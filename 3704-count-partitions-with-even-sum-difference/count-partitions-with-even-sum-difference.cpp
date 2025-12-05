class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int curSum = 0;
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i){
            curSum += nums[i];
            
            if((totalSum - 2 * curSum) % 2 == 0) cnt++;
        }

        return cnt;
    }
};