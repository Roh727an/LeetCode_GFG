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
        // Instead of Node Push the Node value to the End & Delete the Last Node
        ListNode* prev=node;
        ListNode* curr=node;
        int data=node->val;
        while(curr->next!=NULL)
        {
            prev=curr;
            curr->val=curr->next->val;
            curr=curr->next;
        }
        prev->next=curr->next;

    }
};