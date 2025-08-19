class Solution {
public:
    int minSwaps(string s) {
        int op = 0, cl = 0;
        int n = s.size();
        
        for(int i = 0; i < n; ++i){
             if(s[i] == '['){
                op++;
             }else{
                if(op <= 0){
                    cl++;
                }else{
                    op--;
                }
             }
        }

        return (op+1 )/ 2;
      
    }
};