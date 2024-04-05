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
    void rec(TreeNode* root,int num,int &sum){
        num+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=num;
            return;
        }

        if(root->left)
        rec(root->left,num*10,sum);
        if(root->right)
        rec(root->right,num*10,sum);
        num-=root->val;

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        rec(root,0,sum);
        return sum;
    }
};