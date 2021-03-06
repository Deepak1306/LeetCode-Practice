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
    void helper(TreeNode* root , vector<int>& v){
        if(root==NULL){
            return ;
        }
        
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
        
        return ;
        
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        vector<int>v;
        helper(root,v);
        
        TreeNode* curr=new TreeNode(v[0]);
        TreeNode* temp=curr;
        for(int i=1;i<v.size();i++){
            temp->right=new TreeNode(v[i]);
            temp=temp->right;
        }
       
        
        return curr;
        
    }
};