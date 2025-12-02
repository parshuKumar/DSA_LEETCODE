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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root == NULL) return false;
       if(sameTree(root, subRoot)) return true;

       return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));          
    }

    bool sameTree(TreeNode* tree1, TreeNode* tree2){
        if(tree1 == NULL && tree2 == NULL) return true;
        if(tree1 == NULL || tree2 == NULL) return false;
        return(tree1->val == tree2->val && sameTree(tree1->left, tree2->left) && sameTree(tree1->right, tree2->right));
    }
};