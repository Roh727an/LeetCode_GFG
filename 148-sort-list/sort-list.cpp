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
    void findMiddle(ListNode* head,ListNode* &firstList,ListNode* &secondList)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        // Traverse till Not NUll or Last Node
        while(fast!=NULL && fast->next !=NULL)
        {
           
            // Move Fast Pointer By Two Step
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
             // Move Slow Pointer By One Step
             slow=slow->next;
            }
            
        }
        // First list is from start to Middle
        firstList=head;
        // Second List is from Mid's Next to End
        secondList=slow->next;
        // Cut the Connection from Middle to Second List
        slow->next=NULL;

    }
    ListNode* MergeList(ListNode* firstList,ListNode* secondList)
    {
        // Base Case
        if(firstList==NULL)
        return secondList;
        if(secondList==NULL)
        return firstList;

        // Create one Final List
        ListNode* finalList=NULL;
        // First List has Smaller or Equal Element
        if(firstList->val <= secondList->val)
        {
            finalList=firstList;
            // Recursive Call to Update Final List
            finalList -> next=MergeList(firstList->next,secondList);
        }
        else
        {
            finalList=secondList;
            // Recursive Call to Update Final List
            finalList -> next=MergeList(firstList,secondList->next);
        }

        return finalList;
    }
    void Sort(ListNode* &head)
    {
        // Base Case
        if(head==NULL || head->next==NULL)
        return ;
        ListNode* curr=head;
        ListNode* firstList;
        ListNode* secondList;

        findMiddle(curr,firstList,secondList);

        // recursion Call for Both The Halfs
        Sort(firstList);
        Sort(secondList);

        // Merge them
        head=MergeList(firstList,secondList);

    }
    ListNode* sortList(ListNode* head) {
        // your code here
        Sort(head);
        return head;
    }
};