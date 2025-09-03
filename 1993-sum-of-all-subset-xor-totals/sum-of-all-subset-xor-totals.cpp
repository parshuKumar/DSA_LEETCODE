class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xora = 0;
       subset(0, nums, xora, sum );
       return sum;
    }

    void subset(int index, vector<int> &nums, int xora, int &sum){
        if(index >= nums.size()){
            return;
        }
        
        //nopick
        subset(index + 1, nums, xora, sum);
        //pick
        xora ^= nums[index];
        sum += xora;
        subset(index+1, nums, xora, sum);

    }
};