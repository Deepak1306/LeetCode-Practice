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
    bool helper(TreeNode* root, long long min, long long max){
        
        if(root==NULL){
            return true;
        }
        
        bool a=helper(root->left,min,root->val);
        bool b=helper(root->right,root->val,max);
        return root->val > min && root->val < max && a && b ;
        
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN, LLONG_MAX);
    }
};