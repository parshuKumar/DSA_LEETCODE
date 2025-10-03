class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        for(int i = 0;  i < n; ++i){
            int k = i;
            int j = 0;
            while(j < needle.size()){
                if(haystack[k] != needle[j]){
                    break;
                }else{
                    j++;
                    k++;
                }
            }
            if(j == needle.size()){
                return i;
            }
        }
        return -1;
    }
};