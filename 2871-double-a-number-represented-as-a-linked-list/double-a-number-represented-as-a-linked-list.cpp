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
    void Reverse(ListNode* &prev,ListNode* &curr){
        // Base Case
        if(curr==NULL)
        return ;

        ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        Reverse(prev,curr);
    }
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL)
        return head;
        
        ListNode* prev=NULL;
       ListNode* curr=head;
       Reverse(prev,curr);
    //  Reverse head = prev
    ListNode* rev_head=prev;
    int carry=0;
    curr=prev;
    while(curr!=NULL){
        int data=curr->val*2 + carry;
        curr->val=data%10;

        carry=data/10;
        prev=curr;
        curr=curr->next;
    }
    if(carry)
    {
        ListNode *temp=new ListNode(carry);
        prev->next=temp;
        prev=prev->next;
    }
    prev=NULL;
    curr=rev_head;
    Reverse(prev,curr);
    return prev;
    }
};