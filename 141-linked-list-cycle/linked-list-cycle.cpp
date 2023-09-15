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
    bool hasCycle(ListNode *head) {
        //  Tortoise-Hare Approch
        // Intutuion-We can prove that if the Linked List has a Cycle/Loop then fast &  slow Pointer eventually meet at some point for sure. 
        // Base Case
        if(head==NULL || head->next==NULL)
        return false;
        if(head->next==head)
        return true;
        // 1.Create slow Pointer pointing at Head
        ListNode* slow=head;
        // 2.Create fast Pointer pointing at Head
        ListNode* fast=head;
        // 3.Traverse Both the Pointer till one of them becomes NULL-
        while(slow!=NULL && fast!=NULL)
        {
            //a.Update Slow by 1 Step
            slow=slow->next;
            //a.Update fast by 2 Step
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;

            // c.Check if Slow & Fast is Pointing at the Same Node,if yes then the LL has a Cycle-> Return True
            if(slow==fast)
            return true;
        }
        // 4.Since slow/fast one of them becomes NULL so the Lnked List Doesnot Have Any Cycle
        return false;
    }
};