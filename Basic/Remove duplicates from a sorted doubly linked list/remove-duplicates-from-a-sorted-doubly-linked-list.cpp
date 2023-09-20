//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
                // Your code here
        // Base Case
        if (head == NULL || head->next == NULL)
            return head;
        // 1.Create a Prev Pointer Pointing at NULL
        Node *previous = NULL;
        // 2.Create a curr Pointer Pointing at head
        Node *curr = head;
        // 3.Traverse till curr becomes NULL-
        while (curr != NULL)
        {
            // a.Create a forward Pointer Pointing at curr's Next
            Node *forward = curr->next;
            // b.IF it is Duplicate Element then-
            if (forward != NULL && curr->data == forward->data)
            {
                // A.First Node
                if (previous == NULL)
                {
                    // i.point Curr's Next to NULL
                    curr->next = NULL;
                    // ii.point Curr to Froward
                    curr = forward;
                    // iii.point Curr's prev to Previous
                    curr->prev = previous;
                    // iv.Update Head
                    head = curr;
                }
                // B. Not The first Node
                else
                {
                    // a.If previous is Not NULL then Point Previous's Next to Forward
                    if (previous != NULL)
                        previous->next = forward;
                    // b.If Forward is Not NULL then Point Forward's prev to Previous
                    if (forward != NULL)
                        forward->prev = previous;
                    // c.Cut All the Connection from Curr
                    curr->next = NULL;
                    curr->prev = NULL;
                    // d.Update Curr as Forward
                    curr = forward;
                }
            }
            // c.Else Update Pointers-
            else
            {
                //Prev as Curr & Curr as Forward
                previous = curr;
                curr = forward;
            }
        }
        // 4.Return head
        return head;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution obj;
	    head=obj.removeDuplicates(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends