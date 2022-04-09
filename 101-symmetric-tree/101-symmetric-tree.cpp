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
    bool helper(TreeNode*root1,TreeNode*root2){
      if(root1==NULL && root2==NULL){
          return true;
      }
      else if(root1==NULL || root2==NULL){
            return false;
      }
       else if(root1->val !=root2->val){
           return false;
       } 
       
        bool check1=helper(root1->left,root2->right);
        bool check2=helper(root1->right,root2->left);
        
        return check1 && check2;
        
        
         
    }
    
    
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        
        return helper(root,root);
        
        
        
        
        
    }
};