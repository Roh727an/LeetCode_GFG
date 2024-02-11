/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        // Level Order Traversal
        q.push({root, {0, 0}});
        while (!q.empty()) {
            // Pop out First q Front
            auto frontNode = q.front().first;
            // x & level
            int x = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            // Mark
            mp[x][level].insert(frontNode->val);
            // Left Children
            if (frontNode->left)
                q.push({frontNode->left, {x - 1, level + 1}});
            // Right Children
            if (frontNode->right)
                q.push({frontNode->right, {x + 1, level + 1}});
        }
        // Now push elements into ans accordinlgy
        for (auto p : mp) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};