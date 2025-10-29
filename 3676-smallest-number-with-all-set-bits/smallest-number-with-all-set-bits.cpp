class Solution {
public:
    int smallestNumber(int n) {
        
        int i = n;
        while(true){
            int curNum = i;

            if((curNum & (curNum + 1)) == 0){
                return i;
                break; 
            }
            i++;
        }
        return -1;
    }
};