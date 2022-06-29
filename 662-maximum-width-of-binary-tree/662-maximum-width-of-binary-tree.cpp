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
        
        if(!root){
            return 0;
        }
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        int ans=0;
        
        vector<pair<int,long long int>>a;
        while(!q.empty()){
            int size=q.size();
            int first,second;
            int mmin=q.front().second;
            
            for(int i=0;i<size;i++){
                TreeNode*x=q.front().first;
                int curr_id=q.front().second-mmin;
                q.pop();
                
                
                
                if(i==0){
                    first=curr_id;
                }
                
                if(i==size-1){
                    second=curr_id;
                }
                
                if(x->left!=NULL){
                    q.push({x->left,(long long)curr_id*2+1});
                }
                
                if(x->right!=NULL){
                    q.push({x->right,(long long)curr_id*2+2});
                }
                
            }
            ans=max(ans,second-first+1);
            
        }
        
        return ans;
        
        
    }
};