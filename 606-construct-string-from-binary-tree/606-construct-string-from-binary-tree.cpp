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
    string tree2str(TreeNode* root) {
            if(!root){
                return "";
            }
        
        string ans="";
         ans+=to_string(root->val);
        
        string ans1=tree2str(root->left);
        string ans2=tree2str(root->right);
        
        if(ans1=="" && ans2==""){
            return ans;
        }
        
        ans=ans +'('+ ans1 + ')';
        if(ans2!=""){
            ans=ans + '(' + ans2 + ')';
        }
        return ans;
        
        
    }
}; 