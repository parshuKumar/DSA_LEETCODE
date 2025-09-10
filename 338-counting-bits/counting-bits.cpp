class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; ++i){
            string curr = converttoBit(i);
            int numofOnes = calOnes(curr);
            ans.push_back(numofOnes);
        }
        return ans;
    }
    int calOnes(string curr){
        int cnt = 0;
        for(int i = 0; i < curr.size(); ++i){
            if(curr[i] == '1')cnt++;
        }
        return cnt;
    }
    string converttoBit(int n){
        string ans = "";

        while(n > 0){
            
            int rem = n % 2;
            n = n / 2;

            ans += to_string(rem);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};