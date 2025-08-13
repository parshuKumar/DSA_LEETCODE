class Solution {
public:
    int pivotInteger(int n) {
        
        vector<int> pref(n), suff(n), nums(n);

        for(int i = 1; i <= n; ++i){
            nums[i-1] = i;
        }

        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i = 1; i < n; ++i){
            pref[i] = pref[i-1] + nums[i];
        }

        for(int i = n-2; i >= 0; --i){
            suff[i] = suff[i+1] + nums[i];
        }
        
        for(int i = 0; i < n; ++i){
            if(pref[i] == suff[i]){
                return nums[i];
            }
        }
        return -1;
    }
};