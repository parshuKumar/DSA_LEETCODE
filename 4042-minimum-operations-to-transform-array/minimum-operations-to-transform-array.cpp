class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int v = nums2.back();

        long long res = 0;
        int last = 1e9;
        for(int i = 0; i < nums1.size(); ++i){
            int a  = nums1[i], b = nums2[i];

            res += abs(b - a);

            if(a <= v && v <= b || b <= v && v <= a){
                last = 0;
            }else{
                last = min(last, min(abs(a - v), abs(b - v)));
            }

        }

        return res + last + 1;

    }
};