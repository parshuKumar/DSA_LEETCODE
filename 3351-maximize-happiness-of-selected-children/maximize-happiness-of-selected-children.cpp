class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum = 0;
        int t = 0;
        for(int i = 0 ; i < k; ++i){
            if((happiness[i] - t) > 0)
                sum += happiness[i]-t;
            t++;
        }
        return sum;
    }
};