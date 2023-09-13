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
        if(head==NULL ||head->next==NULL)
        return NULL;
        // 1.Take Three Pointer slow & Fast & prev
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=NULL;
    // 2.Traverse till Not NUll or Last Node
        while(fast!=NULL && fast->next !=NULL)
        {
            // a.Make prev as Slow
            prev=slow;
            // b.Move Slow Pointer By One Step
            slow=slow->next;
            // c.Move Fast Pointer By Two Step
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;
        }
        // 3.When Fast Reaches Last Or NULL Slow is Pointing Middle Node
        prev->next=slow->next;
        slow->next=NULL;
        return head;
    }
};