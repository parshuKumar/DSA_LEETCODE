/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;

        solve(root, p, arr1);
        solve(root, q, arr2);

        set<TreeNode*> st(arr1.begin(), arr1.end());
        
        for(int i = arr2.size() - 1; i >= 0; --i){
            if(st.find(arr2[i]) != st.end()){
                return arr2[i];
            } 
        }
        return NULL;
    }

    void solve(TreeNode *root, TreeNode* target, vector<TreeNode*> &arr){
        arr.push_back(root);
        if(root->val == target->val){
            return;
        }

        if(root->val < target->val){
            solve(root->right, target, arr);
        }
        else{
            solve(root->left,target, arr);
        }
    }
};