class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxi = INT_MIN;
        while(left < right){
            int mini = min(height[left], height[right]);
            maxi = max(maxi, mini * (right - left));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }

        }
        return maxi;
    }
};