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
    int count(ListNode* head)
    {
        int cnt=0;
        while(head!=NULL)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
         // Base Case
           if(head==NULL) 
           return head;
           ListNode* temp=head; 
            // 1.Find The Total Number of Nodes in the Linked List
           int countNode=count(temp);
            // 2.If N is greater than Total Number of Nodes then return -1
           if(n>countNode)
           return NULL;
        // 3.If N is Equal to Total Number of Nodes then 
           if(n==countNode)
           {
               head=head->next;
               return head;
           }
            // 3.Find the N from start as N=Total Nodes - N 
           int cnt=countNode-n;

            //4.Iterate till N!=0
            ListNode* curr=head;
            ListNode* prev=head;
           while(cnt--)
           {
            prev=curr;
            curr=curr->next;
           }

            //5.When N becomes 0 it is Our Nth Node from Last
            if(prev!=NULL)
           prev->next=curr->next;
           curr->next=NULL;
           return head;
           */
             //  Optimised Approch

          // 1.Create a Dummy Node & Attach Before Head
          ListNode* dummy=new ListNode(-1);
          dummy->next=head;
          // 2.Create a Fast & Slow Pointer pointing at Dummy Node
          ListNode* fast=dummy;
          ListNode* slow=dummy;

          // 3.Move the Fast Pointer till N times
          for(int i=0;i<n;i++)
          fast=fast->next;

          // 4.Iterate fast & Slow Pointer by One Step till Fast comes at Last Node
          while(fast->next!=NULL)
          {
            fast=fast->next;
            slow=slow->next;
          }
          // 5.Now Slow is Pointing at before Nth Node from Last,so Cut the Connection 
          slow->next=slow->next->next;
          // Now Dummy's Next is Our Head of Final Linked List
          return dummy->next;
    }
};