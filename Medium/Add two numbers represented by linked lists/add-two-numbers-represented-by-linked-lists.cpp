//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
    Node *ReverseList(Node *head)
    {
       Node* prev=NULL;
       Node* curr=head;
       Reverse(prev,curr);
       return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here

        Node* dummy = new Node(-1);
        Node* temp =dummy;
        // 1.Reverse Both The Linked List
        Node* l1=ReverseList(first);
        Node* l2=ReverseList(second);
        int carry=0;
        // 2.Iterate till l1,l2 becomes NULL & also carry becomes 0
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int add=0;
            // a.If l1 is Not NULL then-
            if(l1!=NULL)
            {
                // add data into our sum & Update l1 by 1 step
                add+=l1->data;
                l1=l1->next;
            }
            // b.If l2 is Not NULL then-
            if(l2!=NULL)
            {
                // add data into our sum & Update l2 by 1 step
                add+=l2->data;
                l2=l2->next;
            }

            // c.Add Carry to our sum
            add+=carry;
            // d.Calculate carry
            carry=add/10;
            
            // e.Create a New node of sum value
            Node* nextDigit=new Node(add%10);
            // f.Assign our answer List's next to that node & Update Pointers
            temp->next=nextDigit;
            temp=temp->next;
        }
        // 3.Reverse the Answer List & Return
        return ReverseList(dummy->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends