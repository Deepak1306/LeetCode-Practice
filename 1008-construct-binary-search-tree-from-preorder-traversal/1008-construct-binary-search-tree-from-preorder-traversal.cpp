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
    TreeNode* helper(vector<int>& preorder,int& in,int max){
        if(in==preorder.size() || preorder[in]>=max){
            return NULL;
        }
        
        TreeNode*root=new TreeNode(preorder[in]);
        in++;
        root->left=helper(preorder,in,root->val);
        root->right=helper(preorder,in,max);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int in=0;
        return helper(preorder,in,INT_MAX);
        
    } 
};