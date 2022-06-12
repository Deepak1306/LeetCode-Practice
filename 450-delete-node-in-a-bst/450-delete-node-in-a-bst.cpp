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
    TreeNode*helper(TreeNode*root){
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        }
        
        TreeNode*child=root->right;
        TreeNode*rightChild=lastRight(root->left);
        rightChild->right=child;
        return root->left;
        
    }
    TreeNode* lastRight(TreeNode*root){
        if(root->right==NULL){
            return root;
        }
        
        return lastRight(root->right);
        
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==key){
            return helper(root);
        }
        
        
        if(key<root->val){
            root->left= deleteNode(root->left,key);
        }else{
            root->right =deleteNode(root->right,key);
        }
        
        return root;
        
        
    }
};