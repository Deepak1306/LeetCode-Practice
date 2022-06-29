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
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>m;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode* x=q.front().first;
            int d=q.front().second.first;
            int level=q.front().second.second;
            
            q.pop();
            
            m[d][level].insert(x->val);
            
            if(x->left){
                q.push({x->left,{d-1,level+1}});
            }
            
            if(x->right){
                q.push({x->right,{d+1,level+1}});
            }
        }
        
        for(auto i:m){
            vector<int>c;
            for(auto j:i.second){
                c.insert(c.end(),j.second.begin(),j.second.end());
            }
            
            ans.push_back(c);
            
            
        }
        
        
        return ans;
    }
};