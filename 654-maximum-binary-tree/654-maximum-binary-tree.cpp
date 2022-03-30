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
    TreeNode* helper(vector<int>nums,int si,int ei){
       
        if(si>ei){
            return NULL;
        }
        
        if(si==ei){
             TreeNode* root=new TreeNode(nums[ei]);
            return root;
        }
        
        
        int m=INT_MIN;
        int k=-1;
        
        for(int i=si;i<=ei;i++){
            if(nums[i]>m){
                m=nums[i];
                k=i;
            }
        }
        
        TreeNode* root=new TreeNode(nums[k]);
        
       
        root->left=helper(nums,si,k-1);    
        root->right=helper(nums,k+1,ei);            
        
        
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        
        return helper(nums,0,nums.size()-1);
        
    }
};