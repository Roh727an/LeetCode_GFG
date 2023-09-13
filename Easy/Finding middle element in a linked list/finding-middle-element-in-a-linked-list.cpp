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
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        /*
        // Approch 1
        // Base Case
        if(head==NULL)
        return -1;
        // 1.Count Number of Nodes Present in Linked List
        Node* temp=head;
        int NodeCount=countNodes(temp);
        cout<<"Total Nodes "<<NodeCount<<endl;
        int mid=NodeCount/2;
        int cnt=0;
        // 2.Find Middle Element
        while(cnt<mid)
        {
            head=head->next;
            cnt++;
        }
        return head->data;
        */
        // Approch 2->
        // 1.Take Two Pointer slow & Fast
        Node* slow=head;
        Node* fast=head;
        // 2.Traverse till Not NUll or Last Node
        while(fast!=NULL && fast->next !=NULL)
        {
            // a.Move Slow Pointer By One Step
            slow=slow->next;
            // b.Move Fast Pointer By Two Step
            fast=fast->next;
            if(fast!=NULL)
            fast=fast->next;
        }
        // 3.When Fast Reaches Last Or NULL Slow is Pointing Middle Node
        return slow->data;
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
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends