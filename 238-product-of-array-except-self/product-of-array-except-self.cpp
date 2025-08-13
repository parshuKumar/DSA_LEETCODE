class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> pref(n);
            pref[0] = 1;
            for(int i =1; i < n; ++i){
                pref[i] = pref[i-1] * nums[i-1];
            }
            for(int a : pref){
                cout << a << " ";
            }
            int suff = 1;
            for(int i = n-1; i >= 0; --i){
                pref[i] = pref[i] * suff;
                suff = nums[i] * suff;
            }

        return pref;
    }
};