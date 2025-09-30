class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row  = matrix.size();

        int col =  matrix[0].size();
        vector<int> mat(col);
        int maxi = INT_MIN;

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == '0'){
                    mat[j] = 0;
                }else{
                    mat[j] += 1;
                }
            }
        vector<int> nsl, nsr(col);
        stack<int> st;
        //next smaller left;
        for(int i = 0; i < col; ++i){
            while(!st.empty() && mat[st.top()] >= mat[i]){
                st.pop();
            }
            if(st.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st.top());
            }
            st.push(i);
        }
    
        while(!st.empty()) st.pop();
        //next smaller right;
        for(int i = col-1; i >= 0; --i){
            while(!st.empty() && mat[st.top()] >= mat[i]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = col;
            }else{
                nsr[i] = st.top();
            }
            st.push(i);
        }
        // for(int i = 0; i < col; ++i){
        //     cout << nsl[i] << " ";
        // }
        // cout << endl;
        // for(int i  = 0; i < col; ++i){
        //     cout << nsr[i] << " ";
        // }
       
        for(int i = 0; i < col; ++i){
            int area = (nsr[i] - nsl[i] - 1) * mat[i];
            maxi = max(area, maxi); 
        }
    }
        return maxi;
    }
};