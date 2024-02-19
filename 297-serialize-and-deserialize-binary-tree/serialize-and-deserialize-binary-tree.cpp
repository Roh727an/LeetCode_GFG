/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        string encoded="";
        // Level Order Traversal
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            encoded.append("N,");
            else{
            encoded.append(to_string(curr->val)+",");
            // Push Left & Right
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        return NULL;
        stringstream s(data);
        string temp;
        // Get the First Node(RootNode)
        getline(s,temp,',');
        TreeNode *root = new TreeNode(stoi(temp));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
        // Get the Left
        getline(s,temp,',');
        if(temp=="N")
        curr->left=NULL;
        else{
            TreeNode* tempNode=new TreeNode(stoi(temp));
            q.push(tempNode);
            curr->left=tempNode;
        }
        // Get the Right
        getline(s,temp,',');
        if(temp=="N")
        curr->right=NULL;
        else{
            TreeNode* tempNode=new TreeNode(stoi(temp));
            q.push(tempNode);
            curr->right=tempNode;
        }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));