class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> arr;
        vector<vector<int>> ans;

        solve(candidates, target, arr, 0, 0, ans);

        return ans;
    }

    void solve(vector<int>& candidates, int target, vector<int> arr, int sum,
               int i, vector<vector<int>> &ans) {

   
        if (sum == target) {
            ans.push_back(arr);
             return;
        }
        
    
        if (i == candidates.size() || sum > target) {
            return;
        }

        // pick
        if (sum + candidates[i] <= target) {
            arr.push_back(candidates[i]);
            solve(candidates, target, arr, sum + candidates[i], i, ans);
            arr.pop_back(); 
        }
        
        // not pick and backtrack
        solve(candidates, target, arr, sum, i + 1, ans);
    }
};