class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pref(n, false), suff(n,false);
        pref[0] = true;
        suff[n-1] = true;
        for(int i = 1; i < n; ++i){
            if(nums[i] > nums[i - 1]){
                pref[i] = true;
            }else{
                break;
            }
        }
        for(int i = n-2; i >= 0; --i){
            if(nums[i] > nums[i + 1]){
                suff[i]  = true;
            }else{
                break;
            }
        }
        vector<long long> preSum(n, 0), sufSum(n, 0);
        preSum[0] = nums[0], sufSum[n-1] = nums[n-1];
        for(int i = 1; i < n; ++i){
            preSum[i] = nums[i] + preSum[i-1];
        }
        for(int i = n-2; i >= 0; --i){
            sufSum[i] = nums[i] + sufSum[i+1];    
        }

        long long mini = LLONG_MAX;
        for(int i = 0;  i < n-1; ++i){
            if(pref[i] && suff[i + 1]){
                mini = min(abs(preSum[i] - sufSum[i + 1]), mini);
            }
        }
        // for(int i = 0; i < n; ++i){
        //     cout << pref[i] << " ";
        // }
        // cout << endl;
        //  for(int i = 0; i < n; ++i){
        //     cout << suff[i] << " " ;
        // }
        // cout << endl;
        // for(int i = 0; i < n; ++i){
        //     cout << preSum[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; ++i){
        //     cout << sufSum[i] << " ";
        // }
        return mini == LLONG_MAX ? -1 : mini;
    }
};