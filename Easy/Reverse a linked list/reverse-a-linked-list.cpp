//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    // Function to reverse a linked list.
    void InsertAtHead(Node *&head, int val)
    {
        // 1.Create a New Node
        Node *temp = new Node(val);
        // 2.Point temp's next to head
        temp->next = head;
        // 3.Update head as temp
        head = temp;
    }
    void Reverse(struct Node *&prev,struct Node *&curr){
        // Base Case
        if(curr==NULL)
        return ;

        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        Reverse(prev,curr);
    }
    struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        /*
        // Approch 1-> Brute Force Approch => T.C=O(N) & S.C=O(N)
        Node* rev_head=new Node(head->data);
        head=head->next;
        while(head!=NULL)
        {
            InsertAtHead(rev_head,head->data);
            head=head->next;
        }
        return rev_head;
        */
        //    OPtimised Approch - T.C=O(N) & S.C=O(1)
        /*
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
        */
       Node* prev=NULL;
       Node* curr=head;
       Reverse(prev,curr);
       return prev;
    }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends