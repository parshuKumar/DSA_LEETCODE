class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = target.size();
        
        int prev = 0;
        long long oper = 0;
        for(int i = 0; i < n; ++i){
            int cur = target[i] - nums[i];

            if((prev > 0 && cur < 0) || (cur > 0 && prev < 0)){
                oper += abs(cur);
            }else if (abs(cur) > abs(prev)){
                oper += abs(cur) - abs(prev);
            }

            prev = cur;

        }

        return oper;

        
    }
};