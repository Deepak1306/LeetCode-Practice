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
public:
    
    stack<TreeNode*>st;  //stack -- O(h) Memory

void inorder(TreeNode* root){  //partial inorder i.e. pushing all left elements into stack for a root

   if(root==NULL){
		return;
	}

	st.push(root);

	while(root->left!=NULL){  //pushing all left elements
		st.push(root->left);
		root=root->left;
	}
}
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        TreeNode* top=st.top();  //top stores the topmost index 
	st.pop();

	if(top->right!=NULL){  //check if top has an element to it's right .. if it has, then call inorder
		inorder(top->right);  //inorder will push all the left elements of top's right node
	}

	return top->val;  //return top-> value afterwards
    }
    
    bool hasNext() {
        return !st.empty(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */