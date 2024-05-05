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
        ListNode* prev=node;
        ListNode* curr=node->next;
        while(curr!=NULL){
            prev->val=curr->val;
            if(curr->next!=NULL)
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr;
    }
};