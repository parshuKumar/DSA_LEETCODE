class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto a : s){
            mp[a]++;
        }
        
        auto cmp = [](const pair<char,int> &a, const pair<char,int> &b) {
        return a.second < b.second;  // max-heap by second
        };

        priority_queue<pair<char,int>, vector<pair<char,int>> , decltype(cmp)> pq(cmp);

        for(auto &a : mp){
            pq.push(a);
        }
        string ans;
        while(!pq.empty()){
            int size = pq.top().second;
            char alph = pq.top().first;
            for(int i = 0; i < size; ++i){
                ans.push_back(alph);
            }
            pq.pop();
        }
       return ans;
    }
};