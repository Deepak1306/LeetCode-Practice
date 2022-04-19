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
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorder(root->left);
        
        if(first==NULL && prev->val>root->val){
            first=prev;
        }
        
        if(first!=NULL && prev->val>root->val){
            second=root;
        }
        prev=root;
        inorder(root->right);
        
    }
    
    
    void recoverTree(TreeNode* root) {
        if(root==NULL){
            return ;
        }
        inorder(root);
        
        swap(first->val,second->val);
        
        return ;
        
    }
};