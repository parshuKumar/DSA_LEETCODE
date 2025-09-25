class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n  = arr.size();
        int start = 0, end = n-1;
         while (start <= end) {
        int mid = start + (end - start) / 2;

        // handle edges safely
        if ((mid == 0 || arr[mid] > arr[mid-1]) && 
            (mid == n-1 || arr[mid] > arr[mid+1])) {
            return mid;
        }

        // if slope is rising, move right
        if (mid > 0 &&  arr[mid] < arr[mid-1]) {
            end = mid - 1;
        } 
        else {
            start = mid + 1;
        }
    }
        return -1;
    }
};