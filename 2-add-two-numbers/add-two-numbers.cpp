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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp =dummy;
        // 1.Reverse Both The Linked List
        int carry=0;
        // 2.Iterate till l1,l2 becomes NULL & also carry becomes 0
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int add=0;
            // a.If l1 is Not NULL then-
            if(l1!=NULL)
            {
                // add data into our sum & Update l1 by 1 step
                add+=l1->val;
                l1=l1->next;
            }
            // b.If l2 is Not NULL then-
            if(l2!=NULL)
            {
                // add data into our sum & Update l2 by 1 step
                add+=l2->val;
                l2=l2->next;
            }

            // c.Add Carry to our sum
            add+=carry;
            // d.Calculate carry
            carry=add/10;
            
            // e.Create a New node of sum value
            ListNode* nextDigit=new ListNode(add%10);
            // f.Assign our answer List's next to that node & Update Pointers
            temp->next=nextDigit;
            temp=temp->next;
        }
        // 3.Reverse the Answer List & Return
        return dummy->next; 
    }
};