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
    void dfs(Node* node,Node* check,vector<Node*>&vis){
        vis[check->val]=check;
        for(auto j:node->neighbors){
            if(vis[j->val]==NULL){
                Node*newNode=new Node(j->val);
                dfs(j,newNode,vis);
                check->neighbors.push_back(newNode);
            }else{
                
                check->neighbors.push_back(vis[j->val]);
            }
        }
        
        
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        
        Node*check=new Node(node->val);
        
        vector<Node*>vis(101,NULL);
        dfs(node,check,vis);
            
            return check;
    }
};