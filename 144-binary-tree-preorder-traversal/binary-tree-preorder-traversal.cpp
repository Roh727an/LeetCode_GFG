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
    // Recursion
    void preOrderRec(TreeNode * root)
    {
        // Base Case
        if(root==NULL)
        return ;

        // Push Current Node
        order.push_back(root->val);
        // Move Left
        preOrderRec(root->left);
        // Move Right
        preOrderRec(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // Recursion
        // preOrderRec(root);

        // Base Case
        if(root==NULL)
        return order;
        // 1.Create a Stack to Store Nodes
        stack<TreeNode*>st;
        // 2.Push the Root node into Stack
        st.push(root);
        // 3.Iterate till stack becomes Empty
        while(!st.empty())
        {
            // A.Take out First Node from Stack & Pop it from Stack
            TreeNode* node=st.top();
            st.pop();
            // B.Store the top node value
            order.push_back(node->val);
            // C. If the Right Node is not NULL then Push Right Node into Stack First
            if(node->right!=NULL)
            st.push(node->right);
            // D. If the Left Node is not NULL then Push Left Node into Stack Second
            if(node->left!=NULL)
            st.push(node->left);
        }
        return order;
    }
};