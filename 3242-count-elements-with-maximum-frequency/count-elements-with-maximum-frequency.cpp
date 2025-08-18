class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int a : nums){
            mp[a]++;
        }

        vector<pair<int, int>> v;
        for(auto a : mp){
            v.push_back({a.first, a.second});
        }

        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second > b.second;
        });

        int max = v[0].second;

        int cnt = 0;
        for(auto a : v){
            if(a.second == max){
                cnt+=a.second;
            }else{
                break;
            }
        }
        return cnt;
    }
};