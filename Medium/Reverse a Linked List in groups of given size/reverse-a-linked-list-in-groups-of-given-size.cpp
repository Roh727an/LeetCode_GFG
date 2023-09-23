//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
                // Base Case
        if(head==NULL || head->next==NULL || k==1)
        return head;
        // 1.Create a Dummy Node & Point it's next to head
        node* dummy=new node(0);
        dummy->next=head;
        // 2.Create Three Pointer prev,curr & nextList to Reverse Each Group
        node* prev=dummy;
        node* curr=dummy;
        node* nextList=dummy;
        // 3.Calculate Length of the List
        int length=0;
        while(curr!=NULL)
        {
            length++;
            curr=curr->next;
        }
        // 4.Iterate till length is Greater than or equal to k
        while(nextList!=NULL)
        {
            curr=prev->next;
            nextList=curr->next;
            // Nested Iteration for Links Change(Reverse Logic)
            int itr=length>k?k:length-1;
            for(int i=1;i<itr;i++)
            {
                curr->next=nextList->next;
                nextList->next=prev->next;
                prev->next=nextList;
                nextList=curr->next;
            }
            // Update prev
            prev=curr;
            length-=k;
        }

        return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends