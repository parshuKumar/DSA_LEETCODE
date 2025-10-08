class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res;
        for(int i = 0; i < n; ++i){
            long long s = spells[i];
            long long num = ((success + s - 1) / s);
            int low = 0, high = m-1;
            while(low <= high){
                int mid = low + ((high - low) / 2);
               if(potions[mid] >= num){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            res.push_back(m - low);
        }
        return res;
    }
};