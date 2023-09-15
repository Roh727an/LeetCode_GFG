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
    ListNode* ReverseList(ListNode* head)
    {
    // 1.Create a Prev pointer initially pointing at NULL
        ListNode* prev = NULL;
        // 1.Create a Curr pointer initially pointing at head
        ListNode* curr = head;
        // 3.Traverse till Curr Pointer becomes NULL
        while (curr != NULL)
        {
            // a.Create a Forward Pointer for Curr's Next Track
            ListNode* forward = curr->next;
            // b.Point Currr's Next to Prev
            curr->next = prev;
            // c.Update Prev as Curr
            prev = curr;
            // d.Update Curr as Forward
            curr = forward;
        }
        // 4.AfterTraversal prev becomes the head of Reverse Linked List
        return prev;
  }
    bool isPalindrome(ListNode* head) {
        //Base Case
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* temp=head;
        // 1.Find Middle of Linked List
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        // 2.Reverse mid->next to End
        slow->next=ReverseList(slow->next);

        // 3.Update slow by 1
        slow=slow->next;

        // 4.Compare Both the Half
        while(slow!=NULL)
        {
            if(temp->val != slow->val)
            return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};