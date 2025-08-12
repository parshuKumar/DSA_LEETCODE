class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int a : nums){
            mp[a]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)>> pq(
            [](pair<int,int> a, pair<int, int>b){
                return a.second < b.second;
            }
        );

        for(auto a : mp){
            pair<int,int> p = {a.first, a.second};
            pq.push(p);
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};