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
            TreeNode* fNode=q.front();
            q.pop();
            
            if(fNode==NULL){
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
            
            a.push_back(fNode->val);
            
            if(fNode->left!=NULL){
                q.push(fNode->left);
            }
            if(fNode->right!=NULL){
                q.push(fNode->right);
            }
            
            
        }
        
        return ans;
        
    }
};