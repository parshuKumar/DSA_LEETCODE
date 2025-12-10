class Solution {
public:
    int countPermutations(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[0])
                cnt++;
        }

        if (cnt == n - 1) {
            return modFac(n - 1);
        }

        return 0;
    }

    int modFac(int n){
        long fac = 1;
        int MOD = 1e9 + 7;
        for(int i = 2; i <= n; ++i){
            fac = (fac * i) % MOD;
        }

        return fac;
    }
};