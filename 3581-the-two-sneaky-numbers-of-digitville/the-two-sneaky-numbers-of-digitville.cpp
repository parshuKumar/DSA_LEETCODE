class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;

            if(mp[nums[i]] == 2){
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};