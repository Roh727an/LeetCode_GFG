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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL)
        return head;

        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        ListNode* temp=head;
        while(temp!=NULL){
            // 0 Node Found
            if(temp->val==0){
                // Increment Temp
                temp=temp->next;
                int d=0;
                // Calculate Sum & Move temp
                while(temp!=NULL&& temp->val!=0)
                {
                    d+=temp->val;
                    temp=temp->next;
                }
                // IF sum!=0
                if(d!=0)
                {
                    ListNode* node=new ListNode(d);
                    ans->next=node;
                    ans=ans->next;
                }

            }
        }
        return dummy->next;
        
    }
};