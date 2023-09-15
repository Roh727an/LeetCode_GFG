//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* ReverseList(Node* head)
  {
    // 1.Create a Prev pointer initially pointing at NULL
        Node *prev = NULL;
        // 1.Create a Curr pointer initially pointing at head
        Node *curr = head;
        // 3.Traverse till Curr Pointer becomes NULL
        while (curr != NULL)
        {
            // a.Create a Forward Pointer for Curr's Next Track
            Node *forward = curr->next;
            // b.Point Currr's Next to Prev
            curr->next = prev;
            // c.Update Prev as Curr
            prev = curr;
            // d.Update Curr as Forward
            curr = forward;
        }
        // 4.AfterTraversal prev becomes the head of Reverse Linked List
        return prev;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Base Case
        if(head==NULL || head->next==NULL)
        return head;

        Node* temp=head;
        // 1.Find Middle of Linked List
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        // 2.Reverse mid->next to End
        slow->next=ReverseList(slow->next);

        // 3.Update slow by 1
        slow=slow->next;

        // 4.Compare Both the Half
        while(slow!=NULL)
        {
            if(temp->data != slow->data)
            return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends