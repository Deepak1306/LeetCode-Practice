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
    Node* helper(int in[],int pre[],int i,int ei,int p,int ep,map<int,int>&m){
      if(p<0 || p>ep){
          return NULL;
      }
      Node*root=new Node(pre[p]);
      
      int k=m[pre[p]];
      
       int x=p+k-i;
      
      root->left=helper(in,pre,i,k-1,p+1,x,m);
      root->right=helper(in,pre,k+1,ei,x+1,ep,m);
      
      return root;
      
          
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        
        
        return helper(in,pre,0,n-1,0,n-1,m);
    }
};

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