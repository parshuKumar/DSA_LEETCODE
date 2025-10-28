class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        stringstream ss(text);
        string word;
        while(ss >> word){
            ans++;
            for(int i = 0; i < word.size(); ++i){
                if(st.contains(word[i])){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};