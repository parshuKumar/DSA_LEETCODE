class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col - 1, bottom = row - 1, top = 0;
        int cur = 0;

        while (left <= right && top <= bottom) {
            // left to right
            for (cur = left; cur <= right; ++cur) {
                res.push_back(matrix[top][cur]);
            }
            top++;
            // top to bottom -1
            if (top > bottom) break;
            for (cur = top; cur <= bottom; ++cur) {
                res.push_back(matrix[cur][right]);
            }
            right--;
            // right to left
            if(right < left) break;
            for (cur = right; cur >= left; --cur) {
                res.push_back(matrix[bottom][cur]);
            }
            bottom--;

            // bottom to up - 1           
            for (cur = bottom; cur >= top; --cur) {
                res.push_back(matrix[cur][left]);
            }
            left++;
        }
        return res;
    }
};