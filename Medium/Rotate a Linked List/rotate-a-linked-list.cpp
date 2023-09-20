//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Base Case
        if(k==0)
        return head;
        // 1.Create a Temp Pointer Pointing at head & a cnt Variable to Count Nodes
        Node* temp=head;
        int cnt=1;
        // 2.Traverse till cnt != k
        while(cnt!=k)
        {
            temp=temp->next;
            cnt++;
        }
        // 3.When cnt==k then our temp is standing last Node of Rotated List & temp's next is our NewHead of Rotated List
        Node* newHead=temp->next;
        // 4.If newHead is NULL return head as we cannot rotate or Rotation is it self the original List
        if(newHead==NULL)
        return head;
        Node* lastNode=temp;
        // 5.Point LastNode's Next To NULL
        lastNode->next=NULL;
        // 6.Point temp to newHead & Traverse till temp's next is not null
        temp=newHead;
        while(temp->next!=NULL && temp!=NULL)
        {
            temp=temp->next;
        }
        // 7.If temp is Not became NULL then Point temp's next to head as Rotation
        if(temp!=NULL)
        temp->next=head;
        else
        return head;
        // 8.Return newHead as Our Rotate List Head
        return newHead;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends