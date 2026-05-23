class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute approach : 
        // n ^ 2 for each element there will be a loop to find the target  - curelement

        //map  - n but extra space
        // map<int, int> mp;

        // for(int i = 0; i < numbers.size(); ++i){
        //     int curElement = numbers[i];
        //     int toFind = target - curElement;

        //     if(mp.contains(toFind)){
        //         return {mp[toFind] + 1, i +1};
        //     }

        //     mp[curElement] = i;
        // }
        // return {-1, -1};

        //with constant space but the trade off will be nlogn
        int left = 0, right = nums.size() - 1;

        while(left < right){
            if(nums[left] + nums[right] == target){
                return {left + 1, right + 1};
            }else if(nums[left] + nums[right] < target){
                left++;
            }else{
                right--;
            }

        }

        return {-1, -1};
    }
};