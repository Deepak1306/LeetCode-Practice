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
        vector<vector<int>>ans;
        
        if(root==NULL){
            return ans;
        }
        
        queue<pair<pair<int,int>,TreeNode*>>q;
        map<int,map<int,multiset<int>>>map;
        
        q.push({{0,0},root});
        
        while(!q.empty()){
            TreeNode* node=q.front().second;
            int h=q.front().first.first;
            int v=q.front().first.second;
            
            q.pop();
            
            map[h][v].insert(node->val);
            
            if(node->left){
                q.push({{h-1,v+1},node->left});
            }
            
            if(node->right){
                q.push({{h+1,v+1},node->right});
            }
            
        }
            vector<int>a;
        
        for(auto it:map){
            
            for(auto i:it.second){
                a.insert(a.end(),i.second.begin(),i.second.end());
            }
            
            ans.push_back(a);
            a.clear();            
        }
        
        return ans;
        
    }
};