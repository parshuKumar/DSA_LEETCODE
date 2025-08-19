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

        deque<Node*> q;
        q.push_back(root);
        int depth = 0;
        while(!q.empty()){
            
            int siz = q.size();
           
            for(int i = 0; i < siz; ++i){
                
               Node *temp = q.front();
               q.pop_front();

               if(temp == NULL) continue;

               int arrSize = temp->children.size();
               for(int j = 0; j < arrSize; ++j){
                    if(temp->children[j])
                        q.push_back(temp->children[j]);
               }
            
            }
            depth++;
        }
        return depth;
    }
};