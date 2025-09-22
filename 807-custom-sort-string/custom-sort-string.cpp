class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};
        
        for(char c : s){
            freq[c - 'a']++;
        }
        string ans = "";
        for(char a : order){
            while(freq[a - 'a'] > 0){
                ans += a;
                freq[a - 'a']--;
            }
        }
        
        for(int i = 0; i < 26; ++i){
            while(freq[i]> 0){
                ans += i + 'a';
                freq[i]--;
            }
        }
       return ans;
    }
};