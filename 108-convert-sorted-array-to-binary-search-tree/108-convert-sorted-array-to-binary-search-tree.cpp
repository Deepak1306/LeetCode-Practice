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
    TreeNode* helper(vector<int>& nums, int i , int j){
        if(i>j){
            return NULL;
        }
        else if(i==j){
            TreeNode* b=new TreeNode(nums[i]);
            return b; 
        }
        
        int mid=i+(j-i)/2;
        TreeNode* b=new TreeNode(nums[mid]);
        
        b->left=helper(nums,i,mid-1);
        b->right=helper(nums,mid+1,j);
        
        return b;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return helper(nums,0,nums.size()-1);
    }
};