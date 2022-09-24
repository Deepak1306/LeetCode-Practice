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
    vector<vector<int>>ans;
    
    void solve(TreeNode* root,int k,vector<int>arr){
        arr.push_back(root->val);
        k=k-root->val;
        
        if(root->left==NULL && root->right==NULL){
            if(k==0){
                ans.push_back(arr);
            }
            
            return ;
        }
        
        
        if(root->left){
           solve(root->left,k,arr); 
        }
        
        if(root->right){
          solve(root->right,k,arr);  
        }
        arr.pop_back();
        k+=root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        if(root==NULL){
            return ans;
        }
        
        solve(root,targetSum,arr);
        
        return ans;
    }
};