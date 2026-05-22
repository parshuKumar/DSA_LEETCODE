class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;

        for (; i < nums.size(); ++i) {

            if (j < nums.size() && nums[i] != 0 && nums[j] == 0) {
                swap(nums[i], nums[j]);
                j++;
            }

            if (j < nums.size() && nums[j] != 0)
                j++;
        }
    }
};