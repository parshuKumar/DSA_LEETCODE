class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1;
        int end = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        while(start <= end){
            int mid = start + ((end - start) / 2) ;

            if(ifpsbl(mid, quantities, n)){
                ans = mid;
                end = mid - 1;
            }else{
                start  = mid + 1;
            }
        }
        return ans;
    }
    bool ifpsbl(int mid, vector<int>& quantities, int n){
        int shop = 0;
        for(int i = 0; i < quantities.size(); ++i){
            int num = quantities[i];
            while(num > 0){
                num -= mid;
                shop++;
            }
            if(shop > n) return false;
        }

        return true;
    }
};