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
    void Reverse(ListNode* &prev,ListNode*&curr){
        // Base Case
        if(curr==NULL)
        return ;

        ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        Reverse(prev,curr);
    }
    ListNode* reverseList(ListNode* head) {
        // code here
        // return head of reversed list
        /*
        // Approch 1-> Brute Force Approch => T.C=O(N) & S.C=O(N)
        ListNode* rev_head=new Node(head->data);
        head=head->next;
        while(head!=NULL)
        {
            InsertAtHead(rev_head,head->data);
            head=head->next;
        }
        return rev_head;
        */
        //    OPtimised Approch - T.C=O(N) & S.C=O(1)
        /*
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
        */
       ListNode* prev=NULL;
       ListNode* curr=head;
       Reverse(prev,curr);
       return prev;
    }
};