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
int length(ListNode* head)
{
    int cnt=0;
    while(head!=NULL)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
}
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
  // Base Case
    // Single Node
    if(head1==head2)
    return head1;
    if(head1==NULL || head2==NULL)
    return NULL;
    // 1.Find Length of Both The Linked List
    ListNode* size1=head1;
    ListNode* size2=head2;
    int L1=length(size1);
    int L2=length(size2);
    // 2.Cover the Difference in Longer One
    if(L2 > L1)
    {
        int diff=L2-L1;
        while(diff--)
        {
            head2=head2->next;
        }
    }
    else
    {
        int diff=L1-L2;
        while(diff--)
        {
            head1=head1->next;
        }
    }

    // 3.Iterate both the Pointer till they meet
    while(head1!=head2 && head1!=NULL && head2!=NULL)
    {
        head1=head1->next;
        head2=head2->next;
    }
    if(head1==NULL || head2==NULL)
    return NULL;
    return head1;
    }
};