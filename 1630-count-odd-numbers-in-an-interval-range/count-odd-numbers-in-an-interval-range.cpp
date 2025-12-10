class Solution {
public:
    int countOdds(int low, int high) {
        int lowcnt = 0, highcnt = 0;
        
        if(((low - 1) & 1) == 1) lowcnt = (low - 1) / 2 + 1;
        else lowcnt = (low - 1) / 2;
        
        if((high & 1) == 1) highcnt = high / 2 + 1;
        else highcnt = high / 2;

        return low == 0 ? highcnt : highcnt - lowcnt;
    }
};