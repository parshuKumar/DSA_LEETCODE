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
    int countNodes(TreeNode* root) {
        
        int ans =  dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = dfs(root->left);
        int right =  dfs(root->right);

        return left + right + 1;
    }
};