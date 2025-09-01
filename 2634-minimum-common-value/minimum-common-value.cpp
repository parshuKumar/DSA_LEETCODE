class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        int ans = -1;
        for(int a : nums1){
            s.insert(a);
        }
        for(int b : nums2){
            if(s.contains(b)){
                ans = b;
                break;
            }
        }
       
        return ans;
    }
};