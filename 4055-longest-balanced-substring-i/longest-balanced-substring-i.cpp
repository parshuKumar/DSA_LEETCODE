class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();
        int len = 1;

        for (int i = 0; i < n; ++i) {
             map<char, int> mp;
             
            for (int j = i; j < n; ++j) {
                bool check = true;
                mp[s[j]]++;
                int num = mp.begin()->second;
                for(auto it = mp.begin(); it!= mp.end(); ++it){
                    if(it->second != num){
                        check = false;
                        break;
                    }
                }
                if(check){
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }

    // bool checkValid(string& str) {
    //     unordered_map<char, int> mp;
    //     for (int i = 0; i < str.size(); ++i) {
    //         mp[str[i]]++;
    //     }
    //     int num = mp.begin()->second;

    //     if (mp.size() > 1) {
    //         for (auto it = mp.begin(); it != mp.end(); ++it) {
    //             if (num != it->second) {
    //                 return false;
    //             }
    //         }
    //     }

    //     return true;
    // }
};