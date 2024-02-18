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
    TreeNode* rec(vector<int>& inorder,int inS,int inE,vector<int>& preorder,int preS,int preE,map<int,int>&inMap){
        // Base Case
        if(inS>inE || preS > preE)
        return NULL;

        // Create the Current Node from PreOrder
        TreeNode* curr=new TreeNode(preorder[preS]);
        // Find the curr in Inorder
        int idxCurrInOrder=inMap[curr->val];
        // Number of Elements present in Left of Curr in Inorder will be Left SUbtree
        int numsLeft=idxCurrInOrder-inS;
        // Left Subtree Build Recursive Call
        curr->left=rec(inorder,inS,idxCurrInOrder-1,preorder,preS+1,preS+idxCurrInOrder,inMap);

        curr->right=rec(inorder,idxCurrInOrder+1,inE,preorder,preS+numsLeft+1,preE,inMap);

        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        // Hash Map of Inorder to Optimize Searching
        for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]]=i;

        TreeNode* root=rec(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inMap);
        return root;
    }
};