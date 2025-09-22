class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int a : nums1){
            mp[a]++;
        }
        set<int> ans;
        for(int a : nums2){
            if(mp.contains(a)){
                ans.insert(a);
            }
        }

        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};