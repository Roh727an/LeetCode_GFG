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
    ListNode* middleNode(ListNode* head) {
        /*
        // Approch 1
        // Base Case
        if(head==NULL)
        return -1;
        // 1.Count Number of Nodes Present in Linked List
        ListNode* temp=head;
        int NodeCount=countNodes(temp);
        cout<<"Total Nodes "<<NodeCount<<endl;
        int mid=NodeCount/2;
        int cnt=0;
        // 2.Find Middle Element
        while(cnt<mid)
        {
            head=head->next;
            cnt++;
        }
        return head->data;
        */
        // Approch 2->
        // Base Case
        if(head==NULL ||head->next==NULL)
        return head;
        // 1.Take Two Pointer slow & Fast
        ListNode* slow=head;
        ListNode* fast=head;
        // 2.Traverse till Not NUll or Last Node
        while(fast!=NULL && fast->next !=NULL)
        {
            // a.Move Slow Pointer By One Step
            slow=slow->next;
            // b.Move Fast Pointer By Two Step
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;
        }
        // 3.When Fast Reaches Last Or NULL Slow is Pointing Middle Node
        return slow;
    }
};