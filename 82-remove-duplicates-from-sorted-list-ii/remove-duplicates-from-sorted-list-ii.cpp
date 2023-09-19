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
    ListNode* deleteDuplicates(ListNode* head) {
// Base Case
        if (head == NULL || head->next == NULL)
            return head;
        //  1.Create a Map Data Structure to Count Occurance of Nodes
        map<int, int> mp;
        // 2.Create a Prev Pointer Pointing at NULL
        ListNode *prev = NULL;
        // 3.Create a curr Pointer Pointing at head
        ListNode *curr = head;

        // 4. Count the Number of Occurance of Nodes in the Linked List
        while (curr != NULL)
        {
            mp[curr->val]++;
            curr = curr->next;
        }
        // curr as Head(ReUse)
        curr = head;
        // 4.Traverse till curr becomes NULL-
        while (curr != NULL)
        {
            // a.Current Node has Dupliacte
            if (mp[curr->val] > 1)
            {
                // If Current Node is First Node-Update head
                if (prev == NULL)
                {
                    head = curr->next;
                    curr = curr->next;
                }
                // Else -Simple Deletion Logic
                else
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
            }
            // a.Current Node has No Dupliacte
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        // 5.Return the Head of List
        return head;
    }
};