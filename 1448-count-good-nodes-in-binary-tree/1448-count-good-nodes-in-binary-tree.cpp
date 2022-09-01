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
    void count(TreeNode*root,int &ans,int maxi){
        if(root==NULL){
            return ;
        }
        
        if(root->val>=maxi){
            ans++;
        }
        
        maxi=max(maxi,root->val);
        count(root->left,ans,maxi);
        count(root->right,ans,maxi);
        
    }
    
    int goodNodes(TreeNode* root) {
        
        int ans=0;
        count(root,ans,INT_MIN);
        
        return ans;
        
    }
};