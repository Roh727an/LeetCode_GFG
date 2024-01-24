/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Base Case
        if(head==NULL || head->next==NULL)
        return NULL;
        // Fast Pointer -> 2 Step
        ListNode* fast=head;
        // Slow Pointer -> 1 Step
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        // prev -> slow........fast
       prev->next=slow->next;
       slow->next=NULL;
       return head;
    }
};