/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            int mid = start + (end - start) /2 ;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                start = mid + 1;
            } 
            else end = mid -1;

        }

        int peak = start;

        int a = bs(mountainArr, target, 0 , peak, true);
        int b =  bs(mountainArr, target, peak + 1, n-1 , false );

        return a == -1 && b == -1 ? -1 : a == -1 ? b : a;
        
    }

    int bs(MountainArray &mountainArr, int target, int start, int end, bool asc){
        
        while(start <= end){
            int mid = start + ((end - start) / 2);
            int midVal = mountainArr.get(mid);
            if(midVal == target){
                return mid;
            }
            else if (midVal < target){
                if(asc)
                    start = mid + 1;
                else end = mid -1;
            }
            else{
                if(asc) end = mid - 1;
                else start = mid + 1;
            }
        }
        return -1;
    }

    
};