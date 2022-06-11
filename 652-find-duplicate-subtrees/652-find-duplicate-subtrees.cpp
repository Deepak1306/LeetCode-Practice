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
    string helper(TreeNode*root,vector<TreeNode*>&vt,unordered_map<string,int>&m){
        if(root==NULL){
            return "";
        }
        
       
        string left=helper(root->left,vt,m);
        string right=helper(root->right,vt,m);
        
         string s=to_string(root->val);
        s=s+"#"+left+"#"+right;
        m[s]++;
        
        if(m[s]==2){
            vt.push_back(root);
        }
        
        return s;
        
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>m;
        vector<TreeNode*>vt;
        
        string s=helper(root,vt,m);
        
        return vt;
    }
};