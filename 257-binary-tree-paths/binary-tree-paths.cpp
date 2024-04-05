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
    void rec(TreeNode* root,vector<string>&ans,string ds){
        string d=to_string(root->val);
        ds+=d;
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(ds);
            ds.pop_back();
            return ;
        }
        ds+="->";
        if(root->left) // Move Left if Exist
        rec(root->left,ans,ds);
        if(root->right) // Move right if Exist
        rec(root->right,ans,ds);

        ds.pop_back();
        ds.pop_back();
        ds.pop_back();

    }
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string>ans;  
        if(root==NULL)
        return ans;
      rec(root,ans,"");
      return ans;
    }
};