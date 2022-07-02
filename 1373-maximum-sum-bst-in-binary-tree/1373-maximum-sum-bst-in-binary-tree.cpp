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
class Pair{
    public:
    int minV;
    int maxV;
    int sum;
    
    Pair(int minV,int maxV,int sum){
        this->minV=minV;
        this->maxV=maxV;
        this->sum=sum;
    }
};

class Solution {
public:
      
    Pair solve(TreeNode* root, int& ans){
        if(root==NULL){
            return Pair(INT_MAX, INT_MIN, 0);
        }
        
       Pair left=solve(root->left,ans);
       Pair right=solve(root->right,ans);
        
        if(root->val>left.maxV && root->val < right.minV){
            ans=max(ans,root->val+left.sum+right.sum);
            
            return Pair(min(root->val,left.minV),max(root->val,right.maxV),root->val+left.sum+right.sum);
        }
        ans=max(ans,max(left.sum,right.sum));
        return Pair(INT_MIN,INT_MAX,max(left.sum,right.sum));
        
        
    } 
    
    
    int maxSumBST(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        
        
        Pair a=solve(root,ans);
        
        return ans;
    }
};