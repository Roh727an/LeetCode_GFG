//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        if(head1==NULL || head2==NULL)
    return NULL;
    
    Node *head3=NULL;
    Node*ans=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data==head2->data)
        {
            int value=head1->data;
            //Insert in head3
            Node* temp=new Node(value);
            if(head3==NULL)
            {
              head3=temp;  
              ans=head3;
            }
            
            else
            {
            head3->next=temp;
            head3=head3->next;
            }
            
            head2=head2->next;
             head1=head1->next;
        }
        else if(head1->data > head2->data )
        head2=head2->next;
        else
        head1=head1->next;
    }
    return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends