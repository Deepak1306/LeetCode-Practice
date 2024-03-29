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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        
        if(!root){
            return ans;
        }
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int>a;
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            
            if(node==NULL){
               if(q.empty()){
                   ans.push_back(a);
                   return ans;
               }else{
                   ans.push_back(a);
                   a.clear();
                   q.push(NULL);
                   continue;
               }    
            }
            
            a.push_back(node->val);
            
            for(int i=0;i<node->children.size();i++){
                q.push(node->children[i]);
            }
            
            
        }
        
        return ans;
        
        
    }
};