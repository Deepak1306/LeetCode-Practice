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
    vector<string>ans;
    
    void helper(TreeNode*root, string out){
        if(root==NULL){
            return ;
        }
        else if(root->left==NULL && root->right==NULL){
            string str=to_string(root->val);
            out+=str;
            ans.push_back(out);
        }
        
       string str=to_string(root->val);
        
        helper(root->left, out+str+"->");
        helper(root->right, out+str+"->");
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        helper(root,"");
        
        return ans;
    }
};