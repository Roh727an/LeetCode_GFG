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
        ListNode* prev=NULL;
       ListNode* curr=head;
       Reverse(prev,curr);
       return prev;
    }
};