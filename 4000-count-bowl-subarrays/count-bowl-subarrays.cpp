class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ngl;
        vector<int> ngr(n);
        stack<int> s;
        for(int i = 0; i < n; ++i){
            while(!s.empty() && nums[i] > s.top()){
                s.pop();
            }
            if(s.empty()){
                ngl.push_back(-1);
            }else{
                ngl.push_back(s.top());
            }

            s.push(nums[i]);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n-1; i >= 0; --i){
            while(!s.empty() && nums[i] > s.top()){
                s.pop();
            }
            if(s.empty()){
                ngr[i] = -1;
            }else{
                ngr[i] = s.top();
            }

            s.push(nums[i]);
        }
        long long cnt = 0;
        for(int i =0; i < n; ++i){
            if(ngl[i] == -1 || ngr[i] == -1){
                continue;
            }else{
                cnt++;
            }
        }
        
        return cnt;
    }
};