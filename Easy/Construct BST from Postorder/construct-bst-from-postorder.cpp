//{ Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* rec(int &idx,int post[],int bound){
    // Base Condition
    if(idx<0 || post[idx] < bound)
    return NULL;
    
    Node* curr=new Node(post[idx--]);
        curr->right=rec(idx,post,curr->data);
        curr->left=rec(idx,post,bound);
     return curr;
}
Node *constructTree (int post[], int size)
{
//code here
int idx=size-1;
return rec(idx,post,INT_MIN);
}