/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoRight = true;
        while(!q.empty()){
            vector<int> row;
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* cur = q.front();
                q.pop();

                row.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }

            }
            if(!lefttoRight){
                reverse(row.begin(), row.end());
            }
            lefttoRight = !lefttoRight;
            ans.push_back(row);
        }
        return ans;
    }
};