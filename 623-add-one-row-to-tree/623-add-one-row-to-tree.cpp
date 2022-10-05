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
    
    TreeNode* find(TreeNode* root, int val, int depth, bool check){
        
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            
            if(check){
                temp->left=root;
            }else{
                temp->right=root;
            }
            
            return temp;
        }
        
        if(root==NULL){
            return NULL;
        }
        
        root->left=find(root->left,val,depth-1,true);
        root->right=find(root->right,val,depth-1,false);
        
        return root;
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return find(root,val,depth,true);
    }
};