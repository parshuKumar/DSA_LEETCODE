class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {

        int l = *min_element(begin(nums), end(nums)), h = *max_element(nums.begin(), nums.end());
        long long ans = INT_MAX;
        while(l <= h){
            int mid = l + ((h - l) / 2);

            long long cost1 = calculatecost(mid, nums, cost);
            long long cost2 = calculatecost(mid + 1, nums, cost);
            ans = min(cost1, cost2);
            if(cost1 > cost2){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }

    long long calculatecost(int target, vector<int> &nums, vector<int> &cost){
        int n = nums.size();
        long long total = 0;
        for(int i = 0; i < n; ++i){
            total += (abs(nums[i] - target)) *1LL * cost[i];
        }

        return total;
    }
};