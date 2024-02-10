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
    void rec(TreeNode* root,string ds,vector<string>&ans)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ds+=to_string(root->val);
            ans.push_back(ds);
            return;
        }

        ds+=to_string(root->val);
        if(root->left)
        rec(root->left,ds+"->",ans);
        if(root->right)
        rec(root->right,ds+"->",ans);
        ds.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string>ans;
        if(root==NULL)
        return ans;
        rec(root,"",ans);
        return ans;
    }
};