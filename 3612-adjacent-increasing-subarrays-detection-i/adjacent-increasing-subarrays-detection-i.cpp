class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& arr, int k) {
        if(k == 1) return true;
        int  n = arr.size();
        int m  = (n - (2 * k - 1));
        for(int i = 0; i < m; ++i){
            int cnt1 = 0, cnt2 = 0;
            for(int j = i; j < n - k - 1; ++j){
                if(arr[j + 1] > arr[j]){
                    cnt1++;
                }else{
                    break;
                }
                if(arr[j + k + 1] > arr[j+k]){
                    cnt2++;
                }else{
                    break;
                }
                if(cnt1 == cnt2 && cnt1 == k - 1) return true;
            }
        }
        return false;
    }
};