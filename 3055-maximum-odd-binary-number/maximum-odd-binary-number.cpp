class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt = 0;
        int ind = 0;
        //if the first one then move the 1 to the last
        //if the second ones then move all the 1 to the first;
        int i  = 0, j = n-1;

        while(i <= j){
            if(i < j && s[i] == '0' && s[j] == '1'){
                swap(s[i], s[j]);
            }
            if(s[i] == '1') i++;
            if(s[j] == '0') j--;
        }
        swap(s[j], s[n-1]);
        return s;
    }
};