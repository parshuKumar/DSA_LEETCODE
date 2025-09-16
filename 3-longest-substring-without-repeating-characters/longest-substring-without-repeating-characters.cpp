class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        map<char,int> mp;
        int maxi = 0;
        for(int right = 0, left = 0; right < n; ++right){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            maxi = max(maxi, right-left+1);
        }
        return maxi;

    }
};