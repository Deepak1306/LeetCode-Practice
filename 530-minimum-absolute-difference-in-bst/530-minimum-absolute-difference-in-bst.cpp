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
    void dfs(TreeNode* root,int& ans,TreeNode*& n){
        if(root->left!=NULL){
            dfs(root->left,ans,n);
        }
        
        if(n){
            ans=min(ans,abs(n->val-root->val));
        }
        
        n=root;
        
        if(root->right!=NULL){
            dfs(root->right,ans,n);
        }
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int ans=INT_MAX;
        TreeNode*n=NULL;
        
        dfs(root,ans,n);
        
        return ans;
        
    }
};