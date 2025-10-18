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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>> mp;

        solve(0, 0, root, mp);
        vector<vector<int>> ans;

        for(auto a : mp){
            vector<int> help;
            for(auto level : a.second){
                help.insert(help.end(), level.second.begin(), level.second.end());
            }

            ans.push_back(help);
        }

        return ans;
    }

    void solve(int hz, int lvl, TreeNode* root, map<int, map<int, multiset<int>>> &mp){
        if(root == NULL){
            return;
        }
        mp[hz][lvl].insert(root->val);
        solve(hz - 1, lvl + 1, root->left, mp);
        solve(hz + 1, lvl + 1, root->right, mp);
    }
};