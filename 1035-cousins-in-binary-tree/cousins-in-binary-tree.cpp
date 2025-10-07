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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int foundChild = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; ++i){
                TreeNode* cur = q.front();
                int sameParentCount = 0;
                q.pop();
                if(cur->left){
                    if(cur->left->val == x || cur->left->val == y){
                        sameParentCount++;
                        foundChild++;
                    }
                    q.push(cur->left);
                }
                if(cur->right){
                    if(cur->right->val == x || cur->right->val == y){
                        sameParentCount++;
                        foundChild++;
                    }
                    q.push(cur->right);
                }
                if(sameParentCount == 2) return false;
            }
            if(foundChild == 2) return true;
            if(foundChild == 1) return false;
        }
        return false;
    }
};