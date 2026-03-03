class Solution {
public:
    char findKthBit(int n, int k) {
        // string s = "";

        string ans = func(n);

        return ans[k - 1];
    }

    string func(int i) {
        if (i == 1) {
            return "0";
        }
        string cur = func(i - 1);
        string temp = cur;
        invert(temp);
        reversing(temp);
        return cur + '1' + temp;
    }

    void invert(string& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }
    }

    void reversing(string& s) { reverse(s.begin(), s.end()); }
};