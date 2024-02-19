//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* rec(int inorder[],int inS,int inE,int postorder[],int postS,int postE,map<int,int>&inMap){
        // Base Case
        if(inS>inE || postS > postE)
        return NULL;

        // Create the Current Node from PreOrder
        Node* curr=new Node(postorder[postE]);
        // Find the curr in Inorder
        int idx=inMap[curr->data];
        // Number of Elements present in Left of Curr in Inorder will be Left SUbtree
        int numsLeft=idx-inS;
        // Left Subtree Build Recursive Call
        curr->left=rec(inorder,inS,idx-1,postorder,postS,postS+numsLeft-1,inMap);

        curr->right=rec(inorder,idx+1,inE,postorder,postS+numsLeft,postE-1,inMap);

        return curr;
    }
Node *buildTree(int inorder[], int postorder[], int n) {
    // Your code here
        map<int,int>inMap;
        // Hash Map of Inorder to Optimize Searching
        for(int i=0;i<n;i++)
        inMap[inorder[i]]=i;

        Node* root=rec(inorder,0,n-1,postorder,0,n-1,inMap);
        return root;
}
