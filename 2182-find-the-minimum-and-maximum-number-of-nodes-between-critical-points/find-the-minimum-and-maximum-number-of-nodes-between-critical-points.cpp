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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={INT_MAX,INT_MIN};
        ListNode* curr=head;
        int firstCP=-1,prevCP=-1,prevNode=curr->val,step=0;
        while(curr->next!=NULL){
            int nextNode=curr->next->val,currNode=curr->val;
            step++;
            // Local Maxima|Minima
            if((prevNode<currNode && nextNode<currNode) ||(prevNode>currNode && nextNode>currNode) ){
                // First Critical Point
                if(firstCP==-1){
                    firstCP=step;
                }
                else{
                    // Update Maximum & Minimum
                    ans[0]=min(ans[0],step-prevCP);
                    ans[1]=max(ans[1],step-firstCP);
                }
            prevCP=step;
            }
            // Else Just Move
            prevNode=currNode;
            curr=curr->next;
        }
        if(ans[0]==INT_MAX)
        return {-1,-1};
        return ans;
    }
};