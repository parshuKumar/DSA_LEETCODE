/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        

       if(root == NULL) return 0;
       int ans = solve(root);
       return ans + 1;
    }

    int solve(Node* root){
        
        if(root == NULL){
            return 0;
        }

        vector<int> arr((root->children).size());
        for(int i = 0; i < root->children.size(); ++i){
            arr[i] = solve(root->children[i]);
        }
        if(arr.empty()) return 0;
        return 1 + (*max_element(arr.begin(), arr.end()));
    }
};