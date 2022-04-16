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
    
    TreeNode* helper(TreeNode* root, int& sum){
        if(root==NULL){
            return root;
        }
        
        root->right=helper(root->right,sum);
        root->val=sum+root->val;
        
        sum=root->val;
        
        root->left=helper(root->left,sum);
        
        return root;
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        int sum=0;
        return helper(root,sum);
    }
};