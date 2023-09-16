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
    ListNode* mergeTwoLists(ListNode* firstList, ListNode* secondList) {
         // 1.Base Case
        if(firstList==NULL)
        return secondList;
        if(secondList==NULL)
        return firstList;

        // 2.Create one Final List
        ListNode* finalList=NULL;
        // 3.If First List has Smaller or Equal Element then
        if(firstList->val <= secondList->val)
        {
            // a.Final List is Our First List
            finalList=firstList;
            // b.Recursive Call to Update Final List
            finalList -> next=mergeTwoLists(firstList->next,secondList);
        }
        // 4.If Second List has Smaller  Element then
        else
        {
            // a.Final List is Our Second List
            finalList=secondList;
            // Recursive Call to Update Final List
            finalList -> next=mergeTwoLists(firstList,secondList->next);
        }

        // 5.At the End Return Final List
        return finalList;
    }
};