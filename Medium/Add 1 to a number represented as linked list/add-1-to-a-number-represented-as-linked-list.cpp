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
        cout << node->data%10; 
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

class Solution
{
    public:
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
    Node* addOne(Node *head) 
    {
        // Base Case
        if(head==NULL)
        return NULL;

        Node* ans=head;
        Node* temp=head;
        Node* prev=NULL;
        // 1.Reverse the List
        Node* rev_head=ReverseList(temp);
        Node* re_rev=rev_head;
        int carry=0;
        // 2.Iterate the Reverse List & Take a prev Pointer Along Side -
        while(rev_head!=NULL)
        {
            int add=0;
            // a.If it is First Node then Add 1 to it's Data
            if(prev==NULL)
            add= rev_head->data + 1;
            // b.Else add carry yo it's Data
            else
            add= rev_head->data + carry;
            // c.Calculate carry
            carry= add/10;
            // d.Put Value of that Node
            rev_head->data=add%10;

            // e.Update Pointers- first Update Prev as rev_head & Then Update rev_head to One Step Ahead
            prev=rev_head;
            rev_head=rev_head->next;
        }
        // If there is a Carry Present then Create a New Node & Attach to the Last of Reverse List
        if(carry!=0)
        {
            Node* extra=new Node(carry);
            prev->next=extra;
        }
        // Reverse the List Again & Return the head of that List
        return ReverseList(re_rev);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends