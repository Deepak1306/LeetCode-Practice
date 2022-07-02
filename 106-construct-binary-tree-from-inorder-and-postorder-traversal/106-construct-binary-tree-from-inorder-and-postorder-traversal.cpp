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
    TreeNode* solve(vector<int>& postorder,int sp,int ep, vector<int>& inorder,int si,int ei){
        if(sp>ep || si>ei){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(postorder[ep]);
        int k;
        
       for(int i=si;i<=ei;i++){
           if(inorder[i]==postorder[ep]){
               k=i;
               break;
           }
       }
    
    int x=sp+k-si;
    
    root->left=solve(postorder,sp,x-1,inorder,si,k-1);
    root->right=solve(postorder,x,ep-1,inorder,k+1,ei);
    
     return root;   
        
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=postorder.size();
        int m=inorder.size();
        return solve(postorder,0,n-1,inorder,0,m-1);
    }
};