class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; ++i){
            int val = ((nums[i] % value )+ value)%value;
            mp[val]++; 
        }

        int MEX = 0;
        
        while(mp[MEX % value] > 0){
            mp[MEX % value]--;

            MEX++;
        }

        return MEX;
    }
};