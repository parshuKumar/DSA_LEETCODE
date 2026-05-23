class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //brute approach : 
        // n ^ 2 for each element there will be a loop to find the target  - curelement

        //map  - n but extra space
        map<int, int> mp;

        for(int i = 0; i < numbers.size(); ++i){
            int curElement = numbers[i];
            int toFind = target - curElement;

            if(mp.contains(toFind)){
                return {mp[toFind] + 1, i +1};
            }

            mp[curElement] = i;
        }
        return {-1, -1};
    }
};