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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode (0);
        dummy->next=head;
        unordered_map<int,ListNode*>mp;
        mp[0]=dummy;
        int prefixSum=0;

        // Traverse
        while(head!=NULL){
            // Add into Prefix Sum
            prefixSum+=head->val;
            // Deletion from Map
            if(mp.find(prefixSum)!=mp.end()){
                ListNode* start=mp[prefixSum];
                int pf=prefixSum;
                ListNode* temp=start;
                while(temp->next!=head){
                    temp=temp->next;
                    pf+=temp->val;
                    mp.erase(pf);
                }
                // After Deletion Attach start's next to head's next
                start->next=head->next;
            }
            // Add into Map
            else{
                mp[prefixSum]=head;
            }
            // Update Head
            head=head->next;
        }
        head=dummy->next;
        delete (dummy);
        return head;
    }
};