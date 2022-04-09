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
    void helper(TreeNode*root,int &ans, TreeNode* &prev){
        if(root==NULL){
            return;
        }
        
        helper(root->left,ans,prev);
        
        
        if(prev){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        
        helper(root->right,ans,prev);
        
        
        
        
    } 
    
    int getMinimumDifference(TreeNode* root) {
        
        int ans=INT_MAX;
        TreeNode*prev=NULL;
        
        helper(root,ans,prev);
        return ans;
    }
};