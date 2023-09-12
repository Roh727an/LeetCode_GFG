//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T, i, n, l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head = deleteNode(head,kk);
    printList(head);
    }
    return 0;
}

// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here
    // Base Case
    if(head==NULL)
    return head;
    
    //  1.Delete First Node
    if (x == 1)
    {
        // A.Create a Temp Node Pointing at Head
        Node *temp = head;
        // B.Update head as head's Next
        head = head->next;
        // C.Point Temp's Next to NULL
        temp->next = NULL;
        
        return head;
    }
    // 2.Delete Middle Or Last Node
    else
    {
        Node* ans=head;
        // 1.Create a prev Node Pointing at NULL
        Node *prev = NULL;
        // 2.Create a Curr Node Pointing at head
        Node *curr = head;
        // 3.Traverse Both Node till Position &
        int cnt = 1;
        while (cnt < x)
        {
            // a.First Update prev as curr
            prev = curr;
            // b.Then Update Curr as curr's next
            curr = curr->next;

            cnt++;
        }
        // 4.After Traversal,Points Prev's Next to Curr's Next
        prev->next = curr->next;
        // 5.Points Curr's next to Null
        curr->next = NULL;
        
        return ans;
    }
}
