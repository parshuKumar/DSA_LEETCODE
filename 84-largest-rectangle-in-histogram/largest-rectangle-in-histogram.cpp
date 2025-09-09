class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl;
        vector<int> nsr(n);
        //nextSmallerLeft
        stack<int> st;
        for(int i = 0; i < n; ++i){
            
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st.top());
            }

            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        //nextSmallerRight
        for(int i = n-1; i >= 0; --i){
            
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = st.top();
            }

            st.push(i);
        }


        int maxi = INT_MIN;
        // for(int i = 0; i <n; ++i){
        //     cout << nsr[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i <n; ++i){
        //     cout << nsl[i] << " ";
        // }
        for(int i = 0; i < n; ++i){
            int area = (nsr[i] - nsl[i] - 1) * heights[i];
            maxi = max(area, maxi); 
        }
        return maxi;

    }
};