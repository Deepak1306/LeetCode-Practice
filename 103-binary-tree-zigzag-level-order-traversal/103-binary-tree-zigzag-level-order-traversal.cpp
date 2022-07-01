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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(root==NULL){
            return ans;
        }
        
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        
        vector<int>a;
        s1.push(root);
        
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                TreeNode* f=s1.top();
                s1.pop();
                
                a.push_back(f->val);
                
                if(f->left){
                    s2.push(f->left);
                }
                
                if(f->right){
                    s2.push(f->right);
                }
            }
            if(a.size()!=0){
                
            ans.push_back(a);
            a.clear();
            }
            
            while(!s2.empty()){
                TreeNode* f=s2.top();
                s2.pop();
                
                a.push_back(f->val);
                
                if(f->right){
                    s1.push(f->right);
                }
                
                if(f->left){
                    s1.push(f->left);
                }
                
                
            }
            if(a.size()!=0){
                
            ans.push_back(a);
            a.clear();
            }
            
            
        }
        
        
        return ans;
        
    }
};