/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node*copy, Node*node,vector<Node*>&vis){
        vis[copy->val]=copy;
        
        for(auto j:node->neighbors){
            if(vis[j->val]==NULL){
                Node* n1=new Node(j->val);
                dfs(n1,j,vis);
                 copy->neighbors.push_back(n1);
            }else{
                copy->neighbors.push_back(vis[j->val]);
            }
            
            
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }        
        
        vector<Node*>vis(101,NULL);
        
        Node* copy=new Node(node->val);
        
        dfs(copy,node,vis);
        
        return copy;
        
        
    }
};