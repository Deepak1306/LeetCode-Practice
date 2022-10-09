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
    vector<int>arr;
    void inorder(TreeNode*root, int k){
        if(root==NULL){
            return ;
        }
        
        inorder(root->left,k);
        arr.push_back(root->val);
        inorder(root->right,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        
        inorder(root,k);
        int i=0;
        int j=arr.size()-1;
        
        while(i<j){
            if(arr[i]+arr[j]<k){
                i++;
            }else if(arr[i]+arr[j]>k){
                j--;
            }else{
                return true;
            }
        }
        
        return false;
        
    }
};