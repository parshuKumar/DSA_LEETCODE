class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; ++i){
            pre[i] = pre[i - 1] + nums[i];
        }

        int cnt = 0;
        for(int i = 0; i < n - 1; ++i){
            int first = pre[i];
            int second = pre[n - 1] - first;

            if(abs(second -  first) % 2 == 0) cnt++; 
            
        }

        return cnt;
    }
};