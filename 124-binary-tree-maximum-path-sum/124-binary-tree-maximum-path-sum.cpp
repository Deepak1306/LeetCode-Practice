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
    int solve(TreeNode*root, int& ans){
       
        if(root==NULL){
            return 0;
        }
        
        int lf=solve(root->left,ans);
        int rf=solve(root->right,ans);
        
        int temp=max(root->val , root->val+ max(lf,rf));
        int a=max(temp,lf+rf+root->val);
        ans=max(ans,a);
        
        return temp;
        
    }
    
    int maxPathSum(TreeNode* root) {
       int ans=INT_MIN;
        int a=solve(root,ans);
        
        return ans;
    }
};