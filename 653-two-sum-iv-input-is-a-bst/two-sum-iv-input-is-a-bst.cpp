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

// Iterator Class
class BSTIterator {
private:
    stack<TreeNode*>st;
    // Flag to Determine Wheather Want Next or Before Method
    bool before=false;
    // before = false -> Next
    // before = true -> before
    void pushExtreme(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            // Before Method
            if(before)
            root=root->right;
            // Next Method
            else
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root,bool isBefore) {
        before=isBefore;
        pushExtreme(root);
    }
    
    int move() {

        TreeNode* nextEle=st.top();
        st.pop();
        // Before Method
        if(before)
        pushExtreme(nextEle->left);
         // Next Method
        else
        pushExtreme(nextEle->right);

        return nextEle->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        return false;

        // Initilize Left Iterator
        BSTIterator left(root,false); // next Method
        BSTIterator right(root,true); // Before Method
        int i=left.move(); // next
        int j=right.move(); // before

        // Two Pointer's Approch
        while(i<j)
        {
            if(i+j==k)
            return true;
            if(i+j < k)
            i=left.move();
            else
            j=right.move();
        }
        return false;
    }
};