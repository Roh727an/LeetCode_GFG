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
    vector<int>order;
    // Recursive Approch
    void postOrderRec(TreeNode* root)
    {
        // Base Case
        if(root==NULL)
        return ;
        // Move Left
        postOrderRec(root->left);
        // Move Right
        postOrderRec(root->right);
        // Store  Current Node
        order.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // Recursive Approch
        // postOrderRec(root);
        // Base Case
        if(root==NULL)
        return order;
        // Child Node stores Childerns of the Current Nodes
        stack<TreeNode*>child,postOrder;
        child.push(root);
        // Iterate till child Stack is Not Empty
        while(!child.empty())
        {
            // Pop the First Child
            TreeNode* topChild=child.top();
            child.pop();
            // Push it into the postOrder stack
            postOrder.push(topChild);
            // Push the topChild's Children (left then right)
            if(topChild->left!=NULL)
            child.push(topChild->left);
            if(topChild->right!=NULL)
            child.push(topChild->right);
        }
        // Take out postOrder
        while(!postOrder.empty())
        {
            order.push_back(postOrder.top()->val);
            postOrder.pop();
        }
        return order;
    }
};