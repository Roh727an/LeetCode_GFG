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
    string start,end;
    void dfs(TreeNode* root,string &path, int s, int d){
        if(root==NULL)
        return ;

        if(root->val==s)
        start=path;
        if(root->val==d)
        end=path;

        // Left
        path.push_back('L');
        dfs(root->left,path,s,d);
        path.pop_back();

        // Right
        path.push_back('R');
        dfs(root->right,path,s,d);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path="";
        dfs(root,path,startValue,destValue);
        // Remove Common Part
        int c=0,i=0,j=0;
        while(i<start.length() && j<end.length()){
            if(start[i++]==end[j++])
            c++;
            else
            break;
        }
        start=start.substr(c,start.length()-c);
        end=end.substr(c,end.length()-c);

        for(auto &ch:start)
        ch='U';

        return start+end;
    }
};