/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node!=NULL)
        {
            // 1.Copy Next Node Value to Current Node Value
            node->val=node->next->val;
            // 2.2nd Last Node -> Make the 2nd Last Node as Last Node
            if(node->next!=NULL && node->next->next==NULL)
            node->next=NULL;
            // 3.Update Node
            node=node->next;
        }
    }
};