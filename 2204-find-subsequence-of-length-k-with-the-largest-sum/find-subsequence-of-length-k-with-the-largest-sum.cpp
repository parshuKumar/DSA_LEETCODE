class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; ++i){
            pq.push({nums[i], i});
        }
        map<int , int> mp;
        while(k--){
            mp[pq.top().second] = pq.top().first;
            pq.pop();
        }
        vector<int> res;
        for(auto a : mp){
            res.push_back(a.second);
        }

        return res;
    }
};