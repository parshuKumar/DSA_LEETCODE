class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int oper = target[0];

        for(int i = 1; i < n; ++i){
            oper += max(target[i] - target[i - 1], 0);
        }

        return oper;
    }
};