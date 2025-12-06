class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int tFreq[256] = {0};

        //map the t string
        for(char c : t){
            tFreq[c]++;
        }

        int sFreq[256] = {0};
        string res = s + '0';
        for(int left = 0, right = 0; right < n; ++right){
            sFreq[s[right]]++;

            while(left < right && sFreq[s[left]] > tFreq[s[left]]){
                sFreq[s[left]]--;
                left++;
            }

            if(checkFreq(tFreq, sFreq)){
                if(res.size() > right - left + 1){
                    res = s.substr(left, right - left + 1);
                }
            }
        }
        

        return res == s + '0' ? "" : res;
    }

    bool checkFreq(int t[], int s[]){

        for(int i = 0; i < 256; ++i){
            if(s[i] < t[i]) return false;
        }

        return true;
    }
};