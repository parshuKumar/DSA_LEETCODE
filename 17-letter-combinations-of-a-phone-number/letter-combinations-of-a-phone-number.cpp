class Solution {
public:
    vector<string> letterCombinations(string digits) {

        unordered_map<string, string> mp = {
            {"2" , "abc"},
            {"3" , "def"},
            {"4" , "ghi"},
            {"5" , "jkl"},
            {"6" , "mno"},
            {"7" , "pqrs"},
            {"8" , "tuv"},
            {"9" , "wxyz"}
        };
        vector<string> ans;
        string help;
        solve(digits, 0, digits.size(), mp, ans, help);
        return ans;
    }

    void solve(string &digits, int start, int end, unordered_map<string, string> &mp,  vector<string> &ans, string &help){

        if(start == end){
            if(help != "")
                ans.push_back(help);
            return;
        }

        string curAlpha = mp[string(1, digits[start])]; // 2  It is just I am not using the char instead I am using the string so this string constructor coverts the char to string;

        for(char a : curAlpha){
            help.push_back(a);
            solve(digits, start + 1, end, mp, ans, help);
            help.pop_back();
        }

    }
};