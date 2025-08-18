class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> help;

        solve(k, n , 1, ans , help);
        return ans;
    }

    void solve(int k , int target, int start, vector<vector<int>> &ans, vector<int> &help){
        
        if(start > 9){
            if(target == 0 && help.size() == k){
                ans.push_back(help);
            }
            return;
        }

        //pick
        if(start <= target){
            help.push_back(start);
            solve(k, target - start, start + 1, ans, help);
            help.pop_back();
        }
        //no pick
        solve(k, target, start + 1, ans, help);
    }
};