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
    
    pair<int,int>helper(TreeNode* root){
        pair<int,int>ans;
        
        if(root==NULL){
            ans.first=0;
            ans.second=0;
            return ans;
        }
        
        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);
        
        ans.first=max(left.first,right.first)+1;
        int count=left.first+right.first;
        
        ans.second=max(count,max(left.second,right.second));
        
        return ans;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL){
           return 0;
       }
        
        return helper(root).second;
        
    }
};