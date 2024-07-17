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
    vector<TreeNode*>ans;
    void dfs(TreeNode* node,unordered_set<int>s,bool isRoot){
        // Base Condition
        if(node==NULL)
        return ;

        // Node to Be Deleted
        if(s.find(node->val)!=s.end()){
            // Call Both Child as New Root,i.e Tree
            dfs(node->left,s,true);
            dfs(node->right,s,true);
        }
        // Node is Not Deleted
        else{
            // Push the Root Node into Ans
            if(isRoot)
            ans.push_back(node);
            TreeNode *leftN=node->left;
            TreeNode *rightN=node->right;
            if(leftN!=NULL && s.find(leftN->val)!=s.end())
            node->left=NULL;
            if(rightN!=NULL && s.find(rightN->val)!=s.end())
            node->right=NULL;

            // DFS Call
            dfs(leftN,s,false);
            dfs(rightN,s,false);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>s(to_delete.begin(),to_delete.end());
        
        dfs(root,s,true);
        return ans;
    }
};