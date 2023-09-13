//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends


/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    if(head==NULL || head->next==NULL)
    return NULL;
    // 1.Take Three Pointer slow & Fast & prev
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    // 2.Traverse till Not NUll or Last Node
        while(fast!=NULL && fast->next !=NULL)
        {
            // a.Make prev as Slow
            prev=slow;
            // b.Move Slow Pointer By One Step
            slow=slow->next;
            // c.Move Fast Pointer By Two Step
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;
        }
        // 3.When Fast Reaches Last Or NULL Slow is Pointing Middle Node
        prev->next=slow->next;
        slow->next=NULL;
        return head;
}