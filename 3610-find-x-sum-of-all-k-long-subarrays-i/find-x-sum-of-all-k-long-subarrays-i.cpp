class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int left = 0, right = k;
        vector<int> res;
        while (right <= n) {
            unordered_map<int, int> mp;
            for (int i = left; i < right; ++i) {
                mp[nums[i]]++;
            }   
            priority_queue<pair<int, int>> pq;
            for(auto it = mp.begin(); it != mp.end(); it++){
                pq.push({it->second, it->first});
            }
            int cnt = x;
            int sum = 0;
            while(!pq.empty() && cnt--){
                // cout << pq.top().first << " " << pq.top().second << endl;
                sum += (pq.top().first * pq.top().second);
                pq.pop();
            }
            // cout << "iternation end" << endl;
            res.push_back(sum);
            left++;
            right++;
            
        }

        return res;
    }
};