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
        
        int depth = BFS(root);
        return depth;
    }

    int BFS(TreeNode* root){
        if(!root) return 0;

        deque<TreeNode*> q;
        q.push_back(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();

            while(size > 0){
                    TreeNode* cur = q.front();
                    q.pop_front();
                    size--;
                    if(cur->left){
                        q.push_back(cur->left);
                    }
                    if(cur->right){
                        q.push_back(cur->right);
                    }
            }

            if(!q.empty()) level++;
         
        }
        return level + 1;
    }
};