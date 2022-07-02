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
class BSTIterator {
    TreeNode* node;

    public:
    void inorder(TreeNode* root,TreeNode* &tail){
        if(root==NULL){
            return ;
        }
        inorder(root->left,tail);
        tail->right=root;
        tail->left=NULL;
        tail=tail->right;
        inorder(root->right,tail);
        
    }
    
    BSTIterator(TreeNode* root) {
        TreeNode* temp=root;
        
        while(temp->left!=NULL){
            temp=temp->left;
        }
        node= new TreeNode(temp->val-1);
        TreeNode* tail=node;
        inorder(root,tail);
        
    }
    
    int next() {
        if(node==NULL || node->right==NULL){
            return -1;
        }
        node=node->right;
        
        return node->val;
    }
    
    bool hasNext() {
        if(node==NULL || node->right==NULL){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */