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
    void inOrderRec(TreeNode* root)
    {
        // Base Case
        if(root==NULL)
        return ;
        // Left
        inOrderRec(root->left);
        // Store
        order.push_back(root->val);
        // Right
        inOrderRec(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Recursive Approch
        // inOrderRec(root);
        // Iterative Approch
       // Base Case
        if(root==NULL)
        return order;
        // 1.Create a Stack to Store Nodes
        stack<TreeNode*>st;
        // 2.Create a traverse node as Root
        TreeNode* node=root;
        // 3.Iterate till stack becomes Empty,but initially stack is empty so iterate till true
        while(true)
        {
            // A.If Node is  Not NULL then Push Node into Stack & Move Left
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            // B.If Node is  NULL then-
            else
            {
                // i. if Stack is Empty -> Iteration Over
                if(st.empty())
                break;

                // ii. take out top node from Stack
                node=st.top();
                st.pop();
                // iii.Store it 
                order.push_back(node->val);
                // iv.Move Right of it
                node=node->right;
            }
        }
        return order;
    }
};