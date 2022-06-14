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
    
    void solve(TreeNode*root,TreeNode* &head){
        if(root==NULL){
            return ;
        }
        
        solve(root->right,head);
        
        root->right=head;
        if(head){
            head->left=NULL;
        }
        head=root;
        
        solve(root->left,head);
        
        
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        if(root==NULL){
           return ans; 
       }
        
        TreeNode* head=NULL;
        solve(root,head);
            
            head->left=NULL;
        
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->right;
        }
        
        return ans;
    }
};