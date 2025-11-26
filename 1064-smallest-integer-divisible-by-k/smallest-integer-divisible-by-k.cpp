class Solution {
public:
    int smallestRepunitDivByK(int k) {
    //    7 = have to guess 
    //    1 = 1
    //    3 = 111
    //    9 = 
    //    11
    int ans = 1;
    int i = 1;
    while(i <= k){
        if(ans % k == 0) return i;
        ans = (ans * 10 + 1) % k;
        i++;        
    }
    return -1;
    }
};