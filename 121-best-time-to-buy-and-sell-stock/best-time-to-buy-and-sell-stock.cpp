class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int cur = arr[n-1];
        for(int i = n-2; i >= 0; --i){
            if(arr[i] < cur){
                maxi = max(cur - arr[i], maxi);
            }else{
                cur = arr[i];
            }
        }
        return maxi;
    }
};