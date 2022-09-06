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
    
    bool solve(TreeNode* &root){
        if(!root){
            return false;
        }
        
        bool check1=solve(root->right);
        bool check2=solve(root->left);
        
        if(!check1 && !check2 && root->val==0){
            root=NULL;
            return false;
        }
        
        return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool check=solve(root);
        return root;
    }
};