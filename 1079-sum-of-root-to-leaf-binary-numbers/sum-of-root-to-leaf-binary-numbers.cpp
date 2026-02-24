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
    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        string s = "";
        traverse(root, v, s);
        int sum = 0;
        for(auto a : v){
            sum += convertToNum(a);
        }
        return sum;
    }

    void traverse(TreeNode* root, vector<string> &v, string s){
        if(root == NULL) return;
        s += to_string(root->val);
        if(root->left ==  NULL && root->right == NULL){
            v.push_back(s);
            return;
        }
        
        traverse(root->left, v, s);
        traverse(root->right, v, s);
    }

    int convertToNum(string &a){
        int realpow = 0;
        int num = 0;
        for(int i = a.size() - 1; i >= 0; --i){
            num += ((a[i] - '0') * pow(2, realpow++));
        }

        return num;
    }
};