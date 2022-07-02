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
    TreeNode* solve(vector<int>& preorder, int sp,int ep,vector<int>& inorder,int si,int ei){
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
        
        int x=k-si+sp;
        
        root->left=solve(preorder,sp+1,x,inorder,si,k-1);
        root->right=solve(preorder,x+1,ep,inorder,k+1,ei);
        
        return root;
        
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        inorder.insert(inorder.end(),preorder.begin(),preorder.end());
        
        sort(inorder.begin(),inorder.end());
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        
    }
};