// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
Node* makeBT(int in[],int pre[],int li,int hi,int lp,int hp,map<int,int> &mpp){
        if(lp<0 || lp>hp)return NULL;
    
        int rootData=pre[lp];
        Node* root=new Node(rootData);
        int index = mpp[rootData];
        int numLeft=lp+index-li;
        root->left=makeBT(in,pre,li,index-1,lp+1,numLeft,mpp);
        root->right=makeBT(in,pre,index+1,hi,numLeft+1,hp,mpp);
        return root;
    
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[in[i]]=i;
        }
        return makeBT(in,pre,0,n-1,0,n-1,mpp);
    }};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends