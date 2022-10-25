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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        long long int ans=0;
        while(!q.empty()){
           int size=q.size();
           
           int y=q.front().second;
            
            
            while(size>1){
                int d=q.front().second-y;     
                TreeNode* f=q.front().first;
                q.pop();
                
                if(f->left){
                    q.push({f->left,(long long)2*d+1});
                }
               
                if(f->right){
                    q.push({f->right,(long long)2*d+2});
                }
                
                size--;
            }
            
            TreeNode* f=q.front().first;
            int x=q.front().second-y;
            q.pop();
            
            if(f->left){
                    q.push({f->left,(long long)2*x+1});
            }
               
            if(f->right){
                    q.push({f->right,(long long)2*x+2});
            }
            
            if(ans<x+1){
                ans=x+1;
            }
            
        }
        
        return ans;
    }
};