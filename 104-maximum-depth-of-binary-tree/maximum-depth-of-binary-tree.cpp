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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int d =  solve(root);
        return d;
    }

    int solve(TreeNode* node){
        if(!node) return 0;
        if(node->left ==NULL && node->right == NULL){
            return 1;
        }

        int left = solve(node->left);
        int right = solve(node->right);

        return(max(left, right) + 1);

    }
};