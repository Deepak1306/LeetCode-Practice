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
          
        vector<int>smallAns;
        
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            
            if(front==NULL){
                if(q.empty()){
                    ans.push_back(smallAns);
                    break;
                }else{
                    ans.push_back(smallAns);
                    smallAns.clear();
                    q.push(NULL);
                    continue;
                }
            }
            
            smallAns.push_back(front->val);
            
            if(front->left!=NULL){
                q.push(front->left);
            }
            
            if(front->right!=NULL){
                q.push(front->right);
            }
            
        }
        return ans;
        
    }
};