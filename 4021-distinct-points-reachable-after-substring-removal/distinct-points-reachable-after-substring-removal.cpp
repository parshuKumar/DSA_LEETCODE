class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        int x = 0, y = 0;
        int right, left = 0;
        set<pair<int, int>> ans;
        for(right = 0; right < k; ++right){
            if(s[right] == 'U'){
                y++;
            }else if(s[right] == 'D'){
                y--;
            }else if(s[right] == 'L'){
                x--;
            }else{
                x++;
            }
        }
        ans.insert({x, y});
        while(right < n){
            if(s[right] == 'U'){
                y++;
            }else if(s[right] == 'D'){
                y--;
            }else if(s[right] == 'L'){
                x--;
            }else{
                x++;
            }

            if(s[left] == 'U'){
                y--;
            }else if(s[left] == 'D'){
                y++;
            }else if(s[left] == 'L'){
                x++;
            }else{
                x--;
            }
            ans.insert({x, y});
            left++;
            right++;

        }
        return ans.size();
    }
};