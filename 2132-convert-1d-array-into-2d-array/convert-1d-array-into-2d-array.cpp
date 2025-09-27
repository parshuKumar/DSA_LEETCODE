class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m , vector<int> (n));
        if(m * n > original.size() || m * n < original.size()) return {};
        int j = 0;
        for(int i =0; i < m; ++i){
            int k = 0;
            while(k < n){
                if(j < original.size())
                    ans[i][k] = original[j];
                j++;
                k++;
                
            }
        }
        return ans;
    }
};