class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> k(26, 0);
        int n = s.size();
        for(int i = 0; i < n; ++i){
            k[(s[i] - 'a')]++;
        }

        set<char> st = {'a', 'e', 'i', 'o','u'};
        int maxivowel = 0, maxicons = 0;
        for(char c : st){
            if(k[c - 'a'] > maxivowel){
                maxivowel = k[c - 'a'];
            }
        }

        for(char i = 'a'; i <= 'z'; ++i){
            if(!st.contains(i)){
                if(k[i - 'a'] > maxicons){
                    maxicons = k[i - 'a'];
                }
            }
        }

        return (maxivowel + maxicons);
    }
};