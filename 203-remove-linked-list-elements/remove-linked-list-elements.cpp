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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *root=NULL;
        ListNode *curr=root;
        while(head!=NULL){
            if(head->val!=val)
            {
                ListNode* temp=new ListNode(head->val);
                if(root==NULL)
                {
                root=temp;
                curr=root;
                }
                else{
                curr->next=temp;
                curr=curr->next;
                }
            }
            head=head->next;
        }
        return root;
    }
};