class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] ==1 ){
                ones++;
            }
        }

        if(ones > 0) return n - ones;
        int oper = INT_MAX;
        for(int i = 0; i < n; ++i){
            int curgcd = 0;
            for(int j = i; j < n; ++j){
                curgcd = __gcd(curgcd, nums[j]);

                if(curgcd == 1){
                    oper = min(oper, j - i);
                }
            }
        }

        if(oper == INT_MAX) return -1;

        return oper + n -1; 
    }
};