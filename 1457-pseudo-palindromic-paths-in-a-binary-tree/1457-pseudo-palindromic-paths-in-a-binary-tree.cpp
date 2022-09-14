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
    int ans=0;
    
    void solve(TreeNode* root,int count, map<int,int> &map){
        // cout<<root->val<<" ";
        map[root->val]++;
        if(map[root->val]%2==0){
            count--;
        }else{
            count++;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(count<=1){
                ans++;
            }
            
            map[root->val]--;
            return ;
        }
        
        if(root->left){
        solve(root->left,count,map);
        }
        
        if(root->right){
        solve(root->right,count,map);            
        }
        
        map[root->val]--;
        
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int count=0;
        map<int,int>map;
        solve(root,count,map);
        
        return ans;
        
        
    }
};