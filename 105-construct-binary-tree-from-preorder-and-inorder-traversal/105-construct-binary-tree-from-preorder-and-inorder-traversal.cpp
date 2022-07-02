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
TreeNode* solve(vector<int>& preorder,int sp,int ep, vector<int>& inorder,int si,int ei){
        if(sp>ep || si>ei){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(preorder[sp]);
        int k;
        
       for(int i=si;i<=ei;i++){
           if(inorder[i]==preorder[sp]){
               k=i;
               break;
           }
       }
    
    int x=sp+k-si;
    
    root->left=solve(preorder,sp+1,x,inorder,si,k-1);
    root->right=solve(preorder,x+1,ep,inorder,k+1,ei);
    
     return root;   
        
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        int m=inorder.size();
        return solve(preorder,0,n-1,inorder,0,m-1);
    }
};