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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        vector<int>a;
        
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            
            if(f==NULL){
                if(q.empty()){
                    ans.push_back(a);
                    return ans;
                }else{
                    ans.push_back(a);
                    a.clear();
                    q.push(NULL);
                    continue;
                }
            }
            
            a.push_back(f->val);
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
            
        }
        
        return ans;
        
    }
};