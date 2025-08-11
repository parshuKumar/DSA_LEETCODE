class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;

        for(char a : allowed){
            mp[a] = 1;
        }
       
        int orig = 0;
        for(string a : words){
            bool flag = true;
            for(char c : a ){
                if(mp.find(c) == mp.end()){
                    flag = false;
                }
            }
           if(flag) orig++;
        }

        return orig;
    }
};