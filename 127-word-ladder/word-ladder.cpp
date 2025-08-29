class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> checkwordList;
        for (auto a : wordList) {
            checkwordList.insert(a);
        }
        if(checkwordList.find(endWord) == checkwordList.end()) return 0;
        int level = 1;
        queue<string> q;
        q.push(beginWord);
        int size;
        while (!q.empty()) {
            size = q.size();
    
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return level;
                vector<string> adjWord = findWord(word, checkwordList);

                for (auto w : adjWord) {
                    q.push(w);
                    checkwordList.erase(w);
                }
            }
            level++;
        }
        return 0;
    }
    vector<string> findWord(string word,  unordered_set<string> &checkwordList) {
        vector<string> psb;
        for (int i = 0; i < word.size(); ++i) {
            for (char a = 'a'; a <= 'z'; ++a) {
                if (word[i] == a) {
                    continue;
                }

                string trial = word;
                trial[i] = a;
                if(checkwordList.find(trial) != checkwordList.end()){
                    psb.push_back(trial);
                }
            }
        }
        return psb;
    }
};