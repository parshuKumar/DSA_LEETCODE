class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while (s.size() != 2) {
            for (int i = 1; i < n; ++i) {
                s[i -1] = (((s[i] - '0') + (s[i - 1] - '0')) % 10);
            }
            s.pop_back();
        }
        if(s[0] == s[1]) return true;
        return false;
    }
};