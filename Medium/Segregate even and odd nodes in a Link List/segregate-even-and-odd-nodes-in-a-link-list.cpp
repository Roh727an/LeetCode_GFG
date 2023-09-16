//{ Driver Code Starts
//Initial template for C++

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
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL || head->next==NULL)
        return head;
        // Create Dummy Node
        Node* even=new Node(-1);
        Node* evenTail=even;
        Node* odd=new Node(-1);
        Node* oddTail=odd;

        Node* trav=head;
        // Traverse List
        while(trav!=NULL)
        {
            // Even  
            if(trav->data % 2 == 0)
            {
                evenTail->next=trav;
                evenTail=evenTail->next;
            }
            else
            {
                oddTail->next=trav;
                oddTail=oddTail->next;
            }
            // Update Trav
            trav=trav->next;
        }

        // Merge them & Remove Dummy Nodes
        // Odd->Next is Not NULL
        if(odd->next!=NULL)
        {
            evenTail->next=odd->next;
        }
        else{
            evenTail->next=NULL;
        }
        head=even->next;
        even->next=NULL;
        delete even;
        odd->next=NULL;
        delete odd;
        oddTail->next=NULL;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends